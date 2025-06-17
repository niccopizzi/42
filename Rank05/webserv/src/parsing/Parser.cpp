#include <map>
#include <string>

/* The normal procedure for parsing an HTTP message is to read the start-line into a structure, read each header field line into a hash table by field name until the empty line, and then use the parsed data to determine if a message body is expected */

/* 


#define METHOD_NOT_EXISTENT -2
#define METHOD_NOT_IMPLEMENTED -1


enum MethodType
{
    GET  = 0,
    POST = 1,
    DELETE = 2
};

int     matchMethod(const std::string& requestMethod)
{
    static const char* methods[] = {"GET", "POST", "DELETE", "OPTIONS", "HEAD", 
                                    "PUT", "TRACE", "CONNECT"};

    for (int i = 0; i < 8; ++i)
    {
        if (requestMethod == methods[i])
        {
            return (i);
        }
    }
    return (METHOD_NOT_EXISTENT);
}


struct t_reqLine
{
    MethodType      method;
    std::string     uri;
    std::string     protocol;
    float           version;
} ;


void    parseProtocol(std::string& protocol, t_reqLine& req)
{
    bool    dot = false;

    if (protocol.compare(0, 5, "HTTP/") != 0)
        throw std::runtime_error("Bad request 400\n");
    req.protocol = protocol.substr(0, 5);
    if (!std::isdigit(protocol[5]))
        throw std::runtime_error("Bad request 400\n");
    for (size_t i = 6; i < protocol.size(); ++i)
    {   
        if (protocol[i] == '.' && !dot)
        {
            i++;
            dot = true;
        }
        if (!std::isdigit(protocol[i]))
            throw std::runtime_error("Bad request 400\n");
    }
    if (protocol.compare(5, 4, "1.1") != 0 && 
        protocol.compare(5, 4, "1.0") != 0)
            throw std::runtime_error("Bad request 400\n");
    req.version = std::atof(&protocol[5]);
}

void    parseRequestLine(std::vector<Token>& reqLine)
{
    std::vector<Token>::iterator currToken = reqLine.begin();
    int  method;
    t_reqLine req;


    method = matchMethod(currToken->val);
    if (method == METHOD_NOT_EXISTENT)
        throw std::runtime_error("Bad method 4xx\n");
    else if (method > 3)
        throw std::runtime_error("Method not implemented 4xx\n");
   req.method = static_cast<MethodType>(method);
   currToken++;
   req.uri = currToken->val;
   currToken++;
   parseProtocol(currToken->val, req);
   std::cout << "Final request line \n" << "METHOD : " << req.method;
   std::cout << "\nURI : " << req.uri << '\n';
   std::cout << "Protocol : " << req.protocol << '\n';
   std::cout << "Version : " << req.version << '\n';
}   */