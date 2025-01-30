/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:18:53 by niccol            #+#    #+#             */
/*   Updated: 2024/11/05 15:26:23 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_duplicate(int argc, char *argv[])
{
	int	i;
	int	x;

	i = 1;
	while (i < argc - 1)
	{
		if (argv[i][0] == 0)
			return (true);
		x = i + 1;
		while (x < argc)
		{
			if (ft_strcmp(argv[i], argv[x]) == 0)
				return (true);
			x++;
		}
		i++;
	}
	return (false);
}

int	is_input_valid(int argc, char *argv[])
{
	int			i;
	int			x;
	long long	atoi;

	i = 1;
	while (i < argc)
	{
		x = 0;
		atoi = 0;
		if (argv[i][x] == '-' && argv[i][1] != 0)
			x++;
		while (argv[i][x] != 0)
		{
			if (ft_isdigit(argv[i][x]) == 0)
				return (false);
			atoi = atoi * 10 + (argv[i][x] - 48);
			x++;
		}
		if (argv[i][0] == '-')
			atoi = -atoi;
		if (atoi < -2147483648 || atoi > 2147483647)
			return (false);
		i++;
	}
	return (true);
}
