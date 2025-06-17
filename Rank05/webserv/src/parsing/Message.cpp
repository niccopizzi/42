#include "Message.hpp"

Message::Message()
{
    requestLine.majorVersion = -1;
    requestLine.minorVersion = -1;
    gotEmptyLine = false;
    gotReqLine = false;
    #ifdef DEBUG
        std::cout << "Message constructor called" << std::endl;
    #endif
}

Message::Message(const Message& message)
{
    requestLine.method = message.requestLine.method;
    requestLine.uri = message.requestLine.uri;
    requestLine.http = message.requestLine.http;
    requestLine.majorVersion = message.requestLine.majorVersion;
    requestLine.minorVersion = message.requestLine.minorVersion;
    headerFields = message.headerFields;
    gotReqLine = message.gotReqLine;
    gotEmptyLine = message.gotEmptyLine;
    #ifdef DEBUG
        std::cout << "Message copy constructor called" << std::endl;
    #endif
}

Message& Message::operator=(const Message& message)
{
    requestLine.method = message.requestLine.method;
    requestLine.uri = message.requestLine.uri;
    requestLine.http = message.requestLine.http;;
    requestLine.majorVersion = message.requestLine.majorVersion;
    requestLine.minorVersion = message.requestLine.minorVersion;
    headerFields = message.headerFields;
    gotReqLine = message.gotReqLine;
    gotEmptyLine = message.gotEmptyLine;
    #ifdef DEBUG
        std::cout << "Message Copy assignment operator called" << std::endl;
    #endif
    return (*this);
}

Message::~Message()
{
    requestLine.method.clear();
    requestLine.uri.clear();
    requestLine.http.clear();
    requestLine.minorVersion = -1;
    requestLine.majorVersion = -1;
    headerFields.clear();
    gotReqLine = false;
    gotEmptyLine = false;
    #ifdef DEBUG
        std::cout << "Message destructor called" << std::endl;
    #endif
}

/* void    parseHttpVersion(t_requestLine& reqLine)
{
    size_t  index;

    if (reqLine.http.compare(0, 5, "HTTP/") != 0)
        return;
    if (!std::isdigit(reqLine.http.at(5)))
        return;
    index = 6;
    for (; index < reqLine.http.length(); ++index)
    {
        if (reqLine.http.at(index) == '.')
            break;
        if (!std::isdigit(reqLine.http.at(index)))
            return;
    }
    reqLine.majorVersion = std::atoi(&reqLine.http[5]);
    index++;
    for (int i = index; i < reqLine.http.length(); ++i)
    {
        if (!std::isdigit(reqLine.http.at(i)))
            return;
    }
    reqLine.minorVersion = std::atoi(&reqLine.http[index]);
} */

bool    parseRequestLine(t_requestLine& reqLine)
{
    if (reqLine.method != "GET" && reqLine.method != "POST" && reqLine.method != "DELETE")
    {
        std::cout << reqLine.method << " Error not implemented\n";
        return (false);
    }
    if (reqLine.uri.length() > 1000)
    {
        std::cout << reqLine.uri << " Error uri too long\n";
        return (false);
    }
    if (reqLine.http == "HTTP/1.0")
    {
        reqLine.majorVersion = 1;
        reqLine.minorVersion = 0;
    }
    else if (reqLine.http == "HTTP/1.1")
    {
        reqLine.majorVersion = 1;
        reqLine.minorVersion = 1;
    }
    else
        return (false);
    std::cout << "Printing request line\n";
    std::cout << "Method : " << reqLine.method << '\n';
    std::cout << "URI : " << reqLine.uri << '\n';
    std::cout << "HTTP : " << reqLine.http << '\n';
    std::cout << "major version : " << reqLine.majorVersion << '\n';
    std::cout << "minor version : " << reqLine.minorVersion << '\n';
   /*  if (reqLine.majorVersion == -1 || reqLine.minorVersion == -1)
    {
        std::cout << "Error bad request\n";
        return (false);
    }
    if (reqLine.majorVersion != 1)
    {
        std::cout << reqLine.majorVersion << " Error version not supported\n";
        return (false);
    }
    if (reqLine.minorVersion != 0 && reqLine.minorVersion != 1)
    {
        std::cout << reqLine.minorVersion << " Error version not supported\n";
        return (false);
    } */

    return(true);
}


bool    Message::appendBuffer(const char* buf)
{
    std::stringstream   ss(buf);
    
    if (!gotReqLine)
    {
        ss >> requestLine.method >> requestLine.uri;
        ss >> requestLine.http;
        gotReqLine = true;
        return (parseRequestLine(this->requestLine));
    }
    return (true);
}


int main(int argc, char*argv[])
{
    Message clientMsg;

    if (!clientMsg.appendBuffer(argv[1]))
        std::cout << "Error in the request\n";
    else
        std::cout << "Succesfull request\n";
    return (0);
}