#ifndef CONTACT_HPP_H
# define CONTACT_HPP_H

# include <iostream>

class Contact
{
private:
    std::string     firstName;
    std::string     lastName;
    std::string     nickname;
    std::string     darkestSecret;
    std::string     phoneNum;

public:
            Contact();
            ~Contact();
    void    setContact(std::string firstName, std::string lastName, 
            std::string nickname, std::string secret, std::string phoneNum);
    std::string     getFirstName();
    std::string     getLastName();
    std::string     getNickname();
    std::string     getSecret();
    std::string     getPhoneNum();
    void            displayInfo();
};

# endif