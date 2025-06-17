#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <iostream>


#ifdef DEBUG
static const char* tokenstype[] = 
    {
        "METHOD",
        "URI",
        "PROTOCOL",
        "WHITESPACE",
        "CR",
        "LF",
        "POSSIBLE_END",
        "NEWLINE",
        "FIELD_NAME",
        "FIELD_VALUE",
        "DELIMITER",
        "QUOTED_STRING",
        "COMMENT",
    };
#endif

enum TokenType
{
    METHOD,
    URI,
    PROTOCOL,
    WHITESPACE,
    CR,
    LF,
    POSSIBLE_END,
    NEWLINE,
    FIELD_NAME,
    FIELD_VALUE,
    DELIMITER,
    QUOTED_STRING,
    COMMENT,
};

class Token
{
public:
    TokenType       _type;
    std::string     _value;

    Token();
    Token(TokenType type, std::string& value);
    ~Token();
};

#endif // TOKEN.HPP