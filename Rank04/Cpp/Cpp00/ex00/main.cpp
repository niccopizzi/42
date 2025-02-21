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


#include <iostream>
#include <string>

int main(int ac, char **av)
{
    std::string input;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }
    else
    {
        for (int i = 1; i < ac; i++)
            input += av[i];
        for (std::string::iterator i = input.begin(); i != input.end(); i++)
        {
            std::cout << static_cast <char>(toupper(*i));
        }
        std::cout << std::endl;
    }
    return 0;
}