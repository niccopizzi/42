#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP


#include <cstdlib>
#include <map>
#include <vector>
#include <stdexcept>
#include <stdint.h>
#include "Token.hpp"



class Tokenizer
{
private:
    std::vector<Token> tokens;
    void    passToNextState(TokenType& state);

public:
    Tokenizer();
    ~Tokenizer();

    void    endToken(Token& currToken, TokenType state);
    static void    tokenizeHeaderFields(std::string& message);
    static void    tokenizeRequestLine(std::string& reqLine);

    const std::vector<Token>&    getTokens() const;
};

#ifdef DEBUG
    std::ostream& operator<<(std::ostream& os, Tokenizer& toks);
#endif //DEUG

#endif // TOKENIZER.HPP