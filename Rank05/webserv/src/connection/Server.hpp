#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <vector>
#include <cstdio>
#include "Listener.hpp"
#include "../parsing/Tokenizer.hpp"

namespace   webserv
{
    template<typename T>
    T next(T iterator, size_t n)
    {
        std::advance(iterator, n);
        return (iterator);
    }
}

class Server
{
private:
    std::vector<Listener>           listeners;
    std::vector<ClientConnection>   connections;
    std::vector<struct pollfd>      polls;
    int                             closedListener;

public:
    Server(); 
    Server(const Server& server);
    Server& operator=(const Server& server);
    ~Server();

    void    createListener(const char* hostname, const char* port);
    void    createConnection(Listener& listener, int index);
    void    removeConnection(int index);
    void    pollEvents();
    void    handleClientEvents(struct pollfd& pfd, int i);
    void    addToPolls(const struct pollfd& newPollFd);
    void    addToConnections(const ClientConnection& newConnection);

    const std::vector<Listener>&          getListenersVec() const;
    const std::vector<ClientConnection>&        getConnectionsVec() const;
    const std::vector<struct pollfd>&     getPollsVec() const;
};

std::ostream&   operator<<(std::ostream& os, const Server& server);

#endif // SERVER.HPP