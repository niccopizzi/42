#include "timestamp.hpp"

std::string    createTimeStamp(void)
{
    std::time_t         currtime;
    std::tm*            t;
    std::stringstream   stringStream;

    currtime = time(NULL);
    t = std::gmtime(&currtime);
    if (t->tm_wday < 1 || t->tm_wday > 7 || t->tm_mon < 1 || t->tm_mon > 12)
    {
        return (std::string("Error"));
    }
    stringStream << days[t->tm_wday - 1] << ", " << std::setfill('0') <<
                std::setw(2) << t->tm_mday << " ";
    stringStream << months[t->tm_mon - 1] <<  " " << t->tm_year + 1900 << " ";
    stringStream << std::setfill('0') << std::setw(2) << t->tm_hour << ":"; 
    stringStream << std::setfill('0') << std::setw(2) << t->tm_min << ":";
    stringStream << std::setfill('0') << std::setw(2) << t->tm_sec << " " 
                << t->tm_zone << '\n';
    return (stringStream.str());
}

int main(void)
{
    std::cout << createTimeStamp();
}