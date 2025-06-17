#include "ClientConnection.hpp"

ClientConnection::ClientConnection() : _socketFd(-1) 
{
    std::memset(&peeraddr, 0, sizeof(peeraddr));
    #ifdef DEBUG
        std::cout << "ClientConnection default constructor called\n";
    #endif
}
ClientConnection::ClientConnection(const int fd, const struct sockaddr_storage* addr) : 
                    _socketFd(fd)
{
    std::memcpy(&peeraddr, addr, sizeof(peeraddr));
    #ifdef DEBUG
        std::cout << "ClientConnection constructor called\n";
    #endif
}
ClientConnection::ClientConnection(const ClientConnection& cCon) : _socketFd(cCon._socketFd)
{
    std::memcpy(&peeraddr, &cCon.peeraddr, sizeof(peeraddr));
    #ifdef DEBUG
        std::cout << "ClientConnection copy constructor called\n";
    #endif
}
ClientConnection& ClientConnection::operator=(const ClientConnection& cCon)
{
    if (_socketFd != -1)
        close(_socketFd);
    _socketFd = cCon._socketFd;
    std::memcpy(&peeraddr, &cCon.peeraddr, sizeof(peeraddr));
    #ifdef DEBUG
        std::cout << "ClientConnection copy assignment operator called\n";
    #endif
    return (*this);
}
ClientConnection::~ClientConnection()
{
    /* if (_socketFd != -1)
        close(_socketFd);
    _socketFd = -1; */
    #ifdef DEBUG
        std::cout << "ClientConnection destructor called\n";
    #endif
}

void    ClientConnection::setSocketFd(int fd)
{
    if (_socketFd != -1)
        close(_socketFd);
    _socketFd = fd;
}
void    ClientConnection::setNonBlockState(bool nonBlock)
{
     int flags = fcntl(_socketFd, F_GETFL, 0);

    if (nonBlock)
        fcntl(_socketFd, F_SETFL, flags | O_NONBLOCK);
    else
        fcntl(_socketFd, F_SETFL, flags & (~O_NONBLOCK));
}

int     ClientConnection::getSocketFd() const
{
    return (_socketFd);
}

void    ClientConnection::setPeerAddr(const struct sockaddr_storage* addr)
{
    std::memcpy(&peeraddr, addr, sizeof(peeraddr));
}
const struct sockaddr_storage*    ClientConnection::getPeerAddr() const
{
    return (&peeraddr);
}
    
void    ClientConnection::closeClientConnection()
{
    if (_socketFd != -1)
    {
        close(_socketFd);
        _socketFd = -1;
    }
    std::memset(&peeraddr, 0, sizeof(peeraddr));
}

std::ostream&   operator<<(std::ostream& os, const ClientConnection& cCon)
{
    return (os << "fd : " << cCon.getSocketFd()
            << " - peer address : " << cCon.getPeerAddr()->ss_family << "\n");
}