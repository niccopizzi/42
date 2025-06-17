#include "Tokenizer.hpp"

Tokenizer::Tokenizer()
{
     #ifdef DEBUG
        std::cout << "Tokenizer default constructor called\n";
    #endif
}

Tokenizer::~Tokenizer()
{
     #ifdef DEBUG
        std::cout << "Tokenizer destructor called\n";
    #endif
}

const std::vector<Token>& Tokenizer::getTokens() const
{
    return(tokens);
}

void Tokenizer::tokenizeRequestLine(std::string& message)
{
    uint8_t         c;
    Token           currToken;
    TokenType       state;

    state = METHOD;
    for (size_t i = 0; i < message.length(); ++i)
    {
        c = message.at(i);
        switch (c)
        {
        case ' ':
            if (currToken._type == WHITESPACE)
                continue;
            else 
            {
                endToken(currToken, state);
                passToNextState(state);
                break;
            }
            break;
        case '\r':
            if (state != PROTOCOL)
                throw std::runtime_error("Bad request 400\n");
            if (i + 1 >= message.length() || message.at(i + 1) != '\n')
                throw std::runtime_error("Bad request 400\n");
            endToken(currToken, state);
            state = CR;
            break;
        case '\n':
            if (state == CR)
                return; // end of request line -> parse next
            else
                throw std::runtime_error("Bad request 400\n");
            break;
        default:
            if (currToken._type == WHITESPACE)
                currToken._type = state;
            currToken._value.append(1, c);
            break;
        }
    }
}

void  Tokenizer::endToken(Token& currToken, TokenType state)
{
    currToken._type = state;
    tokens.push_back(currToken);
    currToken._value.clear();
    currToken._type = WHITESPACE;
}

void    Tokenizer::passToNextState(TokenType& state)
{
    switch (state)
    {
    case METHOD:
        state = URI;
        break;
    case URI:
        state = PROTOCOL;
        break;
    default:
        throw std::runtime_error("Bad request!\n");
    }
}

void    Tokenizer::tokenizeHeaderFields(std::string& message)
{
    uint8_t         c;
    Token           currToken;
    TokenType       state;

    state = NEWLINE;
    for (size_t i = 0; i < message.length(); ++i)
    {
        c = message.at(i);
        switch (c)
        {
        case ',':
            switch (state)
            {
            case QUOTED_STRING:
                currToken._value.append(1, c);
                break;
            case WHITESPACE:
                break;
            default:
                endToken(currToken, state);
                state = WHITESPACE;
                break;
            }
            break;
        case '\"':
            switch (state)
            {
            case QUOTED_STRING:
                endToken(currToken, state);
                state = WHITESPACE;
                break;
            case WHITESPACE:
                state = QUOTED_STRING;
                break;
            default:
                endToken(currToken, state);
                state = QUOTED_STRING;
                break;
            }
            break;
        case '\t': //TODO
            break;
        case ' ':
            switch (state)
            {
            case NEWLINE: 
                throw std::runtime_error("Line folding not supported\n");
                break;
            case FIELD_NAME:
                throw std::runtime_error("Bad request\n");
                break;
            case WHITESPACE:
                break;
            default:
                endToken(currToken, state);
                state = WHITESPACE;
                break;
            }
            break;
        case ':':
            switch (state)
            {
            case FIELD_NAME:
                endToken(currToken, state);
                state = FIELD_VALUE;
                break;
            default:
                currToken._value.append(1, c);
                break;
            }
            break;
        case '\r':
            if (i + 1 >= message.length() || message.at(i + 1) != '\n')
                throw std::runtime_error("Bad request 400\n");
            switch (state)
            {
            case NEWLINE:
                state = POSSIBLE_END;
                break;
            default:
                endToken(currToken, state);
                state = CR;
                break;
            }
            break;
        case '\n':
            switch (state)
            {
            case POSSIBLE_END:
                return; //end of the transmission
                break;
            case CR:
                state = NEWLINE;
                break;
            default:
                throw std::runtime_error("Bad request 400\n");
                break;
            }
            break;
        default:
            currToken._value.append(1, c);
            break;
        }
    }
    #ifdef DEBUG
        std::cout << *this;
    #endif
}


#ifdef DEBUG
    std::ostream& operator<<(std::ostream& os, Tokenizer& toks)
    {
        const std::vector<Token>& tokns = toks.getTokens();

        for (std::vector<Token>::const_iterator it = tokns.begin(); 
                it != tokns.end(); ++it)
        {
            os << "Token (" << tokenstype[it->_type] << ") Value " << it->_value
                <<std::endl;
        }
        return (os);
    }
#endif //DEBUG