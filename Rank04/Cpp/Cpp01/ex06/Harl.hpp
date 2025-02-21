/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:18:57 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/12 14:18:21 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );

public:
    typedef void (Harl::*FuncPtr)();
    
    static FuncPtr functionsPtr[4];
    FuncPtr getFuncPtr( std::string level);
    void    complain( std::string level );
    void    moreComplain ( int level );
    Harl( void );
    ~Harl( void );
};

#endif