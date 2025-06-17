#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    std::ifstream   f(filename.c_str());
    std::string     line;
    float           value;

    if (f.bad())
        throw std::runtime_error("Error in opening the file provided");
    while (getline(f, line, ','))
    {
        getline(f, line, ',');
        
        mp.insert(std::make_pair(line, ));
    }
    for (std::map<std::string, float>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        std::cout << "Key : " << it->first << " Value : " << it->second << "\n";
    }
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& bitcoinexchange) :
mp(bitcoinexchange.mp)
{
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& bitcoinexchange)
{
    mp.erase(mp.begin(), mp.end());
    mp = bitcoinexchange.mp;
    std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    mp.erase(mp.begin(), mp.end());
    std::cout << "BitcoinExchange destructor called" << std::endl;
}