#include "webserv.hpp"
//Date: Mon, 09 Jun 2025 15:18:24 GMT

int main(int argc, char* argv[])
{
    Server  server;

    server.createListener(NULL, "6942");
    if (argc != 1)
        std::cout << argv[1] << std::endl;
    while(true)
    {
        server.pollEvents();
    }
    return (0);
}
