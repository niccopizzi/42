#include "BitcoinExchange.hpp"

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cout << "Usage error : please provide a csv file to show how much you lost on bitcoins!\n";
        return (1);
    }
    std::string filename = argv[1];
    if (filename.find(".csv", filename.length() - 4) == filename.npos)
    {
        std::cout << "Nooo, provide a csv file please!\n";
        return (2);
    }
    BitcoinExchange bp("data.csv");
}