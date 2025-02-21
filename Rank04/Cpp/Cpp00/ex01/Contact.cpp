/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:43:23 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/10 11:59:27 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    //std::cout << "Creating new contact" << std::endl;
    Contact::firstName = "";
    Contact::lastName  = "";
    Contact::nickname  = "";
    Contact::darkestSecret = "";
    Contact::phoneNum = "";
}

Contact::~Contact()
{
    //std::cout << "Destroying contact FOREVER!" << std::endl;
}

void    Contact::setContact(std::string firstName, std::string lastName, 
            std::string nickname, std::string secret, std::string phoneNum)
{
    Contact::firstName = firstName;
    Contact::lastName = lastName;
    Contact::nickname = nickname;
    Contact::darkestSecret = secret;
    Contact::phoneNum = phoneNum;
}

std::string Contact::getFirstName()
{
    return (Contact::firstName);
}

std::string Contact::getLastName()
{
    return (Contact::lastName);
}
std::string Contact::getNickname()
{
    return (Contact::nickname);
}
std::string Contact::getSecret()
{
    return (Contact::darkestSecret);
}

std::string Contact::getPhoneNum()
{
    return (Contact::phoneNum);
}

void    Contact::displayInfo()
{
    std::cout << "First Name        : " << Contact::getFirstName() << "\n";
    std::cout << "Last  Name        : " << Contact::getLastName() << "\n";
    std::cout << "Nickname          : " << Contact::getNickname() << "\n";
    std::cout << "Darkest Secret    : " << Contact::getSecret() << "\n";
    std::cout << "Phone number      : " << Contact::getPhoneNum() << std::endl; 
}