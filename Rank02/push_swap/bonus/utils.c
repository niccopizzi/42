/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:30:43 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:26:40 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	check_if_correct(t_stack **stack_a, t_stack **stack_b, int total_moves)
{
	if (stack_b != NULL && *stack_b != NULL)
	{
		ft_lstfree(stack_b);
		return (false);
	}
	if (is_sorted(*stack_a) == false)
		return (false);
	if ((stack_size(*stack_a) == 100 && total_moves > 700)
		|| (stack_size(*stack_a) == 500 && total_moves > 5500))
		return (false);
	return (true);
}

void	free_all_and_exit(char *instruction, t_stack **stack_a,
		t_stack **stack_b)
{
	write(STDERR_FILENO, "Error\n", 6);
	free(instruction);
	if (*stack_a != NULL)
		ft_lstfree(stack_a);
	if (*stack_b != NULL)
		ft_lstfree(stack_b);
	exit(EXIT_FAILURE);
}
