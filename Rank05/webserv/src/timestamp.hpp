#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>

const std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

const std::string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

/* std::time_t currtime = time(NULL);
std::tm*    tm_time = std::gmtime(&currtime); */

#endif // TIMESTAMP.HPP