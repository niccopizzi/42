/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:08:19 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/10 11:02:20 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_H
# define PHONEBOOK_HPP_H

#include <iostream>
#include <iomanip>
#include "Contact.hpp"


# define RED "\x1b[31m"
# define REEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

# define BOLD "\x1b[1m"
# define DIM "\x1b[2m"
# define ITALIC "\x1b[3m"
# define UNDERLINE "\x1b[4m"
# define BLINKING "\x1b[5m"
# define REVERSE "\x1b[7m"
# define STRIKETHROUGH "\x1b[9m"

class PhoneBook
{
private:
    int     savedContacts;
    int     currentIndex;

public:
    Contact Contacts[8];
            PhoneBook();
    int     getIndex();
    int     getSavedContacts();
    Contact getContact(int index);
    void    setIndex(int index);
    void    setSavedContacts(int num);
    void    displayContacts();
    void    addContact();
};


# endif