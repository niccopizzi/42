#include "Server.hpp"

void Server::pollEvents()
{
    int     ret;

    ret = poll(polls.data(), polls.size(), -1);

    if (ret == -1)  
        throw (std::runtime_error(strerror(errno)));
    for (size_t i = 0; i < polls.size(); ++i)
    {
        if (polls.at(i).revents != 0)
        {
            if (i < listeners.size())
            {
                createConnection(listeners.at(i), i);
            }
            else
            {
               handleClientEvents(polls.at(i), i);
            }
        }
    }
}

void Server::createConnection(Listener& listener, int index)
{
    try
    {
        ClientConnection      newConnection(listener.acceptConnection());
        struct pollfd   newConnPollFd;
    
        newConnPollFd.fd = newConnection.getSocketFd();
        newConnPollFd.events = POLLIN;
        newConnPollFd.revents = 0;

        addToConnections(newConnection);
        addToPolls(newConnPollFd);
        #ifdef DEBUG
            std::cout << "New connection created at port : " << listener.getPort()
                << "\n";
        #endif
    }
    catch(const std::runtime_error& e)
    {
        polls.at(index).fd = -1;
        closedListener = index;
        std::cerr << "Could not open new connection : " << e.what() << '\n';
    }
}


void Server::createListener(const char* hostname, const char* port)
{
    struct pollfd   listenerPollFd;
    Listener        newListener(hostname, port); 

    newListener.createSocket(AF_UNSPEC, SOCK_STREAM);
    newListener.startListen(SOMAXCONN);
    listeners.push_back(newListener);
    listenerPollFd.fd = newListener.getSocketFd();
    listenerPollFd.events = POLLIN;
    listenerPollFd.revents = 0;
    polls.push_back(listenerPollFd);
}

void Server::handleClientEvents(struct pollfd& pfd, int i)
{
    std::string buffer;
    int     bytes;

    if (pfd.revents & POLLHUP)
    {
        #ifdef DEBUG
            std::cout << "Pollhup event received\n";
        #endif
        removeConnection(i);
    }
    else
    {
        bytes = read(pfd.fd, buffer.data(), 1000);
        if (bytes == 0)
        {
            #ifdef DEBUG
                std::cout << "EOF received\n";
            #endif
            removeConnection(i);
            return;
        }
        Tokenizer::tokenizeHeaderFields(buffer);
        std::cout << "Message from client\n---\n" << buffer;
        std::cout << "---\n";
        send(pfd.fd, "HTTP/1.1 200 OK\r\n\r\nHeloa!", strlen("HTTP/1.1 200 OK\r\n\r\nHeloa!"), 0);
    }
}

void Server::removeConnection(int index)
{
    #ifdef DEBUG
        std::cout << "Removing connection\n";
    #endif
    connections.at(index - listeners.size()).closeClientConnection();
    polls.at(index).fd = -1;
    if (closedListener >= 0)
    {
        listeners.at(closedListener).createSocket();
        listeners.at(closedListener).startListen(SOMAXCONN);
        polls.at(closedListener).fd = listeners.at(closedListener).getSocketFd();
        closedListener = -1;
    }
}


void    Server::addToPolls(const struct pollfd& newPollFd)
{
    for (std::vector<struct pollfd>::iterator it = polls.begin();
            it != polls.end(); ++it)
    {
        if (it->fd == -1)
        {
            *it = newPollFd;
            return;
        }
    }
    polls.push_back(newPollFd);
}

void    Server::addToConnections(const ClientConnection& newConnection)
{
    for (std::vector<ClientConnection>::iterator it = connections.begin();
            it != connections.end(); ++it)
    {
        if (it->getSocketFd() == -1)
        {
            *it = newConnection;
            return;
        }
    }
    connections.push_back(newConnection);
}

