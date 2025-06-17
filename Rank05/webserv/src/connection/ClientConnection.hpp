#ifndef CLIENTCONNECTION_HPP
#define CLIENTCONNECTION_HPP

#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <poll.h>
#include <cerrno>
#include <cstring>
#include <iostream>

class ClientConnection
{
private:
    int                     _socketFd;
    struct sockaddr_storage peeraddr;
    std::string             _clientMsg;

public:
    ClientConnection();
    ClientConnection(const int fd, const struct sockaddr_storage* addr);
    ClientConnection(const ClientConnection& cCon);
    ClientConnection& operator=(const ClientConnection& cCon);
    ~ClientConnection();

    void    setSocketFd(int fd);
    void    setNonBlockState(bool nonBlock);
    int     getSocketFd() const;
    void    setPeerAddr(const struct sockaddr_storage* addr);
    const struct sockaddr_storage*    getPeerAddr() const;

    void    closeClientConnection();
};

std::ostream&   operator<<(std::ostream& os, const ClientConnection& cCon);

#endif // CLIENTCONNECTION.HPP