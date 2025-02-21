/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:29:21 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/10 12:04:10 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <sstream>

bool    isValidIndex(std::string input, int savedContacts, int *index)
{
    int value;
    
    if (input.empty())
    {
        std::cout << "Mmmmh why don't you type something?\n";
        return (false);
    }
    for(std::string::iterator it = input.begin(); it != input.end(); ++it)
    {
        if (*it < '0' || *it > '9')
        {
            std::cout << "Nooo why? Please insert only digits\n";
            return (false);
        }
    }
    std::stringstream(input) >> value;
    if (value < 1 || value > savedContacts)
    {
        std::cout << "Index out of range !\n";
        std::cout << "These are the accepted values\n";
        for (int i = 1; i <= savedContacts; i++)
            std::cout << i << "\n";
        return (false);
    }
    *index = value;
    return (true);
}

void    handleSearchCommand(PhoneBook *newPhoneBook)
{
    std::string     value;
    int             index;
    int             savedContacts;

    savedContacts = newPhoneBook->getSavedContacts();
    if (savedContacts == 0)
    {
        std::cout<< "\x1b[34m""\x1b[1m""\tYOU HAVE NO CONTACTS""\x1b[0m"<< std::endl;
        return;
    }
    newPhoneBook->displayContacts();
    do
    {
        std::cout << "Please insert the index of the contact you want to display\n> ";
        getline(std::cin, value);
        if (std::cin.eof())
        {
            std::cout << "Well in this case my job is done here, goodbye!\n";
            return ;
        }
    } while (!isValidIndex(value, savedContacts, &index));
    newPhoneBook->Contacts[index - 1].displayInfo();
}

int main(void)
{
    std::string input;
    PhoneBook newPhoneBook;
    
    std::cout << "\x1b[34m""\x1b[1m"; //set bold blue color
    std::cout << "\n\tWELCOME TO YOUR PHONE BOOK MY FRIEND!\n";
    std::cout <<  "\x1b[0m"; //reset colors
    std::cout << "\n\t\tWhat would you like to do?\n\n";
    
    do
    {
        std::cout << "Please select one of the following options:\n\n";
        std::cout << "\x1b[1m" "->\t1)ADD\n\n->\t2)SEARCH\n\n->\t3)EXIT\n\n" "\x1b[0m";
        std:: cout << "> ";
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "You inserted EOF - Goodbye!" <<std::endl;
            return (0);
        } 
        if (input == "ADD")
        {
            newPhoneBook.addContact();
        }
        else if (input == "SEARCH")
        {
            handleSearchCommand(&newPhoneBook);   
        }
    } while (input != "EXIT" && std::cin.good());
    std::cout << "See you!" << std::endl;
    return (0);
}