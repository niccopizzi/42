#include "Listener.hpp"

Listener::Listener() : _hostname("127.0.0.1"), _port("8080"), _socketFd(-1)
{
    #ifdef DEBUG
        std::cout << "Listener default constructor called\n";
    #endif
}

Listener::Listener(const char* hostname, const char* port) : 
        _hostname(hostname), _port(port), _socketFd(-1)
{
    #ifdef DEBUG
        std::cout << "Listener constructor called\n";
    #endif
}

Listener::Listener(const Listener& listener) : 
        _hostname(listener._hostname), _port(listener._port), _socketFd(listener._socketFd) 
{
    #ifdef DEBUG
        std::cout << "Listener copy constructor called\n";
    #endif
}

Listener& Listener::operator=(const Listener& listener)
{
    _hostname = listener._hostname;
    _port = listener._port;
    if (_socketFd != -1)
        close(_socketFd);
    _socketFd = listener._socketFd;
    #ifdef DEBUG
        std::cout << "Listener copy assignment operator called\n";
    #endif
    return (*this);
}

Listener::~Listener()
{
    /* if (_socketFd != -1)
        close(_socketFd); */
    #ifdef DEBUG
        std::cout << "Listener destructor called\n";
    #endif
}
void            Listener::createSocket(int ai_family, int ai_socktype)
{
    int                 err;
    int                 yes = 1;
    struct addrinfo*    info;
    struct addrinfo*    it;
    struct addrinfo     hints;

    std::memset(&hints, 0, sizeof(hints));
    hints.ai_family = ai_family;
    hints.ai_socktype = ai_socktype;
    hints.ai_flags = AI_PASSIVE;
    err = getaddrinfo(_hostname, _port, &hints, &info);
    if (err != 0)
        throw std::runtime_error(gai_strerror(err));
    for (it = info; it != NULL; it = it->ai_next)
    {
        _socketFd = socket(it->ai_family, it->ai_socktype | SOCK_NONBLOCK, it->ai_protocol);
        if (_socketFd == -1)
            continue;
        setsockopt(_socketFd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
        if (bind(_socketFd, it->ai_addr, it->ai_addrlen) == 0)
            break;
    }
    err = (it == NULL);
    freeaddrinfo(info);
    if (err)
        throw std::runtime_error("Could not bind to any socket");
}

void            Listener::startListen(int queue) const
{
    if (_socketFd == -1)
        return;
    if (listen(_socketFd, queue) != 0)
        throw std::runtime_error(strerror(errno));
    #ifdef DEBUG
        std::cout << "Listening on port " << _port << '\n';
    #endif
}
int             Listener::getSocketFd() const
{
    return (_socketFd);
}
const char*     Listener::getHostName() const
{
    return (_hostname);
}
const char*     Listener::getPort() const
{
    return (_port);
}

void            Listener::setNonBlockState(bool nonBlock)
{
    int flags = fcntl(_socketFd, F_GETFL, 0);

    if (nonBlock)
        fcntl(_socketFd, F_SETFL, flags | O_NONBLOCK);
    else
        fcntl(_socketFd, F_SETFL, flags & (~O_NONBLOCK));
}

void            Listener::setSocketFd(int fd)
{
    _socketFd = fd;
}

ClientConnection      Listener::acceptConnection() 
{
    int                     newFd;
    struct sockaddr_storage s;
    socklen_t               addrlen;

    if (_socketFd == -1)
        throw(std::runtime_error("Socket is closed\n"));
    addrlen = sizeof(s);
    newFd = accept(_socketFd, (struct sockaddr*)&s, &addrlen);
    if (newFd == -1)
    {
        close(_socketFd);
        _socketFd = -1;
        throw(std::runtime_error(strerror(errno)));
    }
    fcntl(newFd, F_SETFL, O_NONBLOCK);
    return (ClientConnection(newFd, &s));
}


std::ostream&   operator<<(std::ostream& os, const Listener& listener)
{
    const char* hostname;
    const char* port;

    hostname = listener.getHostName();
    port = listener.getPort();
    os << "hostname : ";
    hostname != NULL ? os << hostname : os << "NULL";
    os << " - port : ";
    port != NULL ? os << port : os << "NULL";
    os << " - fd : " << listener.getSocketFd() << "\n";
    return (os);
}