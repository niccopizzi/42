#include "Token.hpp"

Token::Token() : _type(WHITESPACE), _value()
{
    #ifdef DEBUG
        std::cout << "Token default constructor called\n";
    #endif
}

Token::Token(TokenType type, std::string& value) : _type(type), _value(value)
{
    #ifdef DEBUG
        std::cout << "Token constructor called\n";
    #endif
}

Token::~Token()
{
    _type = WHITESPACE;
    #ifdef DEBUG
        std::cout << "Token destructor called\n";
    #endif
}