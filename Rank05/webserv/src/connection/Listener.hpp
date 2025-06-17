#ifndef LISTENER_HPP
#define LISTENER_HPP

#include "ClientConnection.hpp"

class Listener
{
private:
    const char* _hostname;
    const char* _port;
    int         _socketFd;

public:
    Listener();
    Listener(const char* hostname, const char* port);
    Listener(const Listener& listener);
    Listener& operator=(const Listener& listener);
    ~Listener();


    void            createSocket(int ai_family = AF_UNSPEC, 
                                    int ai_socktype = SOCK_STREAM);
    void            startListen(int queue) const;
    int             getSocketFd() const;
    const char*     getHostName() const;
    const char*     getPort() const;
    void            setNonBlockState(bool nonBlock);
    void            setSocketFd(int fd);

    ClientConnection      acceptConnection();
};


std::ostream&   operator<<(std::ostream& os, const Listener& listener);

#endif // LISTENER.HPP