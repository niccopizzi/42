#include <iostream>
#include <fstream>
#include <string>

int sed(char* filename, std::string s1, std::string s2)
{
    std::ifstream       infile(filename);
    std::ofstream       outfile(static_cast <std::string>(filename).append(".replace").c_str());
    std::string         line;
    std::size_t         index;


    if (infile.fail() || outfile.fail())
    {
        std::cout << "Failed to open the files\n";
        if (!outfile.fail())
            outfile.close();
        if(!infile.fail())
            infile.close();
        return (3);
    }
    while (getline(infile, line))
    {
        index = line.find(s1);
        while (index != std::string::npos)
        {
            line.erase(index, s1.length());
            line.insert(index, s2);
            index = line.find(s1, index + s2.length());
        }
        outfile << line;
        if (!infile.eof())
            outfile <<"\n";
    }
    outfile.close();
    infile.close();
    return (0);
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Invalid usage, please insert\n";
        std::cout << "1) <filename>\n";
        std::cout << "2) <string to replace>\n";
        std::cout << "3) <string to insert>\n";
        return (1);
    }

    if (!argv[1][0] || !argv[2][0] || !argv[3][0])
    {
        std::cout << "Error, paramaters cannot be empty\n";
        return (2);
    }
    return (sed(argv[1], argv[2], argv[3]));
}
