/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:24:51 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/12 14:18:56 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::FuncPtr Harl::functionsPtr[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon ";
    std::cout << "for my 7XL-double-cheese-triple-pickle-special-ketchup burger. ";
    std::cout << "I really do!\n";
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << " You didn’t put enough bacon in my burger!";
    std::cout << " If you did, I wouldn’t be asking for more!\n";
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I’ve been coming for years whereas you started working here since last month.\n";
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

Harl::FuncPtr Harl::getFuncPtr( std::string level)
{
    std::string     array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (array[i] == level)
            return (functionsPtr[i]);
    }
    return (NULL);
}

void    Harl::complain( std::string level )
{
    FuncPtr func = getFuncPtr( level );
    if (func == NULL)
        return ;
    (this->*func)();
}

void    Harl::moreComplain ( int level )
{
    std::string     array[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = level; i < 4; i++)
    {
        std::cout << "[ " << array[i] << " ]\n";
        complain( array[i]);
        std::cout << "\n";
    }
}

Harl::Harl ( void )
{
    //std::cout << "Time to complain!\n";
}

Harl::~Harl()
{
   // std::cout << "I was too soft this time, but next time !!\n";
}