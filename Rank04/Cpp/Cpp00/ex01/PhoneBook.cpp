/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:56:01 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/10 12:08:27 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    std::cout << "Creating a new Phonebook!" << std::endl;
    this->currentIndex = 0;
    this->savedContacts = 0;
}

void    PhoneBook::setIndex(int index)
{
    if (index == 8)
        index = 0;
    this->currentIndex = index;
}
int     PhoneBook::getIndex()
{
    return (this->currentIndex);
}

Contact PhoneBook::getContact(int index)
{
    return (this->Contacts[index]);
}

void    PhoneBook::setSavedContacts(int num)
{
    if (num > 8)
        return;
    this->savedContacts = num;
}

int    PhoneBook::getSavedContacts()
{
    return (this->savedContacts);
}


std::string     setOutputString(std::string value)
{
    if (value.length() >= 10)
    {
        value.at(9) = '.';
        return (value.substr(0, 10));
    }
    return (value);
}

void    PhoneBook::displayContacts()
{
    std::string value;
    int         i;
    
    std::cout<< "\x1b[34m""\x1b[1m""\t\tLIST OF CONTACTS""\x1b[0m"<< std::endl;
    std::cout << std::setw(10) << "INDEX" << "|";
    std::cout << std::setw(10) << "FIRST NAME" << "|";
    std::cout << std::setw(10) << "LAST NAME" << "|";
    std::cout << std::setw(10) << "NICKNAME" << "|\n\n";
    
    i = 1;
    while (i <= this->getSavedContacts())
    {
        std::cout << std::setw(10) << i << "|";
        value = setOutputString(this->Contacts[i - 1].getFirstName());
        std::cout << std::setw(10) << value << "|";
        value = setOutputString(this->Contacts[i - 1].getLastName());
        std::cout << std::setw(10) << value << "|";
        value = setOutputString(this->Contacts[i - 1].getNickname());
        std::cout << std::setw(10) << value << "|\n";
        i++;
    }
}

bool    isValidInput(std::string input, int index)
{
    if (input.empty())
    {
        std::cerr << "Error! A Contact cannot have empty variables\n";
        return (false);
    }
    if (index == 2 || index == 3)
        return (true); /*Skip checks for nickname and darkest secret*/
    for(std::string::iterator it = input.begin(); it != input.end(); it++)
    {
        if (*it >= '0' && *it <= '9')
        {
            if (index != 4)
            {
                std::cerr << "Error! A Name cannot have numbers!\n";
                return (false);
            }
        }
        else if (index == 4) //this gets executed if the input is not numbers and we are validating a number
        {
            std::cerr << "Error! A phone number can have only digits!\n";
            return (false);
        }
    }
    return (true);
}

void    PhoneBook::addContact()
{
    const   char    *strings[5] = {"First Name", "Last Name", "Nickname", 
                                            "Darkest Secret", "Phone Number"};
    std::string     userinput[5];
    int             index;
    
    for (int i = 0; i < 5; ++i)
    {
        do
        {
            std::cout << "Insert " << strings[i] << std::endl;
            std::cout << "> ";
            getline(std::cin , userinput[i]);
            if (std::cin.eof()) 
                return;
            std::cin.clear();
        }   while (!isValidInput(userinput[i], i));
    }
    index = this->getIndex();
    this->Contacts[index].setContact(userinput[0], userinput[1], userinput[2], userinput[3], userinput[4]);
    this->setIndex(index + 1);
    this->setSavedContacts(this->getSavedContacts() + 1);
}
