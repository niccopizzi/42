/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 12:27:40 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/12 14:01:44 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main(void)
{
    Harl newHarl = Harl();

    //newHarl.complain("DEBUG");
    //newHarl.complain("INFO");
    //newHarl.complain("WARNING");
    //newHarl.complain("ERROR");
    newHarl.complain("notexist");
    return (0);
}