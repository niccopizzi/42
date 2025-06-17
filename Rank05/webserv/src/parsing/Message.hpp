#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <cstdlib>

struct t_requestLine
{
    std::string method;
    std::string uri;
    std::string protocol;
    int         majorVersion;
    int         minorVersion;
};

struct t_responseLine
{
    std::string protocol;
    std::string reasonPhrase;
    int         statusCode;
};


//Request-Line   = Method SP Request-URI SP HTTP-Version CRLF
//Status-Line    = HTTP-Version SP Status-Code SP Reason-Phrase CRLF

enum httpState
{
    REQUEST_LINE,
    RESPONSE_LINE,
    WHITESPACE,
    METHOD,
    URI,
    PROTOCOL,
    MAJOR_VERSION,
    MINOR_VERSION,
    STATUS_CODE,    
};

class Message
{
private:
    t_requestLine   requestLine;
    std::map<std::string, std::string> headerFields;
    httpState       currState;
    
public:
    Message();
    Message(const Message& message);
    Message& operator=(const Message& message);
    ~Message();
    bool    appendBuffer(const char* buf);
};


#endif // MESSAGE.HPP