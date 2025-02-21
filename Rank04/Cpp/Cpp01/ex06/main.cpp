#include "Harl.hpp"

int whichLevel(std::string level)
{
    std::string     array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i ++)
    {
        if (level == array[i])
            return (i);
    }
    return (-1);
}

int main(int argc, char *argv[])
{
    Harl    harl = Harl();

    std::string level; 

    if (argc != 2 || !argv[1][0])
        return (0);
    level = argv[1];
    switch (whichLevel(level))
    {
    case (0):
        harl.moreComplain(0);
        break;
    case (1):
        harl.moreComplain(1);
        break;
    case (2):
        harl.moreComplain(2);
        break;
    case (3):
        harl.moreComplain(3);
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        break;
    }
}