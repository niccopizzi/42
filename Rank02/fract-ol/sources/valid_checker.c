/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:50:18 by npizzi            #+#    #+#             */
/*   Updated: 2024/11/04 19:45:13 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	is_fractal_valid(char *fractal)
{
	char	**possible_fractals;
	int		i;

	possible_fractals = (char *[]){"Mandelbrot", "mandelbrot", "Julia",
		"julia", "Burning Ship", "Burning ship", "burning ship"};
	i = 0;
	while (i <= 6)
	{
		if (ft_strncmp(fractal, possible_fractals[i], 13) == 0)
			return (possible_fractals[i][0]);
		i++;
	}
	return (false);
}

bool	is_complex_valid(char *str)
{
	int	i;

	if (str == NULL || str[0] == 0)
		return (false);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == 'i' && str[i + 1] == 0)
			return (true);
		if (ft_isspace(str[i]) == false && (ft_isdigit(str[i]) == false)
			&& str[i] != '+' && str[i] != '-' && str[i] != '.')
			return (false);
		if (str[i] == '.' && (ft_isdigit(str[i - 1]) == false
				|| ft_isdigit(str[i + 1]) == false))
			return (false);
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] != ' ' && (ft_isdigit(str[i + 1]) == false))
				return (false);
		}
		i++;
	}
	return (true);
}
