#include "Server.hpp"

Server::Server()
{
    listeners.reserve(5);
    connections.reserve(20);
    polls.reserve(25);
    closedListener = -1;
    #ifdef DEBUG
        std::cout << "Server default constructor called" << std::endl;
    #endif
}

Server::Server(const Server& server) :  
                listeners(server.listeners), connections(server.connections),
                polls(server.polls), closedListener(server.closedListener)
{

    #ifdef DEBUG
        std::cout << "Server copy constructor called" << std::endl;
    #endif
}

Server& Server::operator=(const Server& server)
{
    listeners.clear();
    listeners = server.listeners;
    connections.clear();
    connections = server.connections;
    polls.clear();
    polls = server.polls;
    closedListener = server.closedListener;
    #ifdef DEBUG
        std::cout << "Server Copy assignment operator called" << std::endl;
    #endif
    return (*this);
}

const std::vector<Listener>&    Server::getListenersVec() const
{
    return (listeners);
}

const std::vector<ClientConnection>&  Server::getConnectionsVec() const    
{
    return (connections);
}

const std::vector<struct pollfd>& Server::getPollsVec() const
{
    return (polls);
}

Server::~Server()
{
    for (std::vector<struct pollfd>::iterator it = polls.begin(); 
                it != polls.end(); ++it)
    {
        if (it->fd != -1)
        {
            close(it->fd);
            it->fd = -1;
        }
    }
    #ifdef DEBUG
        std::cout << "Server destructor called" << std::endl;
    #endif
}

std::ostream&   operator<<(std::ostream& os, const Server& server)
{
    const std::vector<Listener>& listenrs = server.getListenersVec();
    const std::vector<ClientConnection>& connections = server.getConnectionsVec();
    const std::vector<struct pollfd> polls = server.getPollsVec();

    os << "Printing listeners - Tot : " << listenrs.size() << "\n";

    for (std::vector<Listener>::const_iterator it = listenrs.begin(); 
            it != listenrs.end(); ++it)
    {
        os << "\n" << *it << "\n";   
    }

    os << "Printing connections - Tot : " << connections.size() << "\n";

    for (std::vector<ClientConnection>::const_iterator it = connections.begin();
            it != connections.end(); ++it)
    {
        os << "\n" << *it << "\n";
    }

    os << "Printing polls - Tot : " << polls.size() << "\n\n";

    for (std::vector<struct pollfd>::const_iterator it = polls.begin();
            it != polls.end(); ++it)
    {
        os << "fd : " << it->fd;
        os << " - events : " << it->events;
        os << " - revents : " << it->revents;
        os << "\n";
    }
    os << "\n";

    return (os);
}