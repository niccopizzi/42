#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <exception>

class BitcoinExchange
{
    private:
        std::map<std::string, float> mp;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& filename);
        BitcoinExchange(const BitcoinExchange& ); 
        BitcoinExchange& operator=(const BitcoinExchange& );
        ~BitcoinExchange(); 
};

#endif // BITCOINEXCHANGE.HPP