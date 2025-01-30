/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:12:39 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:11:53 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_instruction(char *instruction, t_stack **stack_a, t_stack **stack_b)
{
	char	**possible_instructions;
	int		i;

	i = 0;
	possible_instructions = (char *[]){"ra\n", "rra\n", "sa\n", "pa\n", "rb\n",
		"rrb\n", "sb\n", "pb\n", "rr\n", "rrr\n", "ss\n"};
	while (i <= 10)
	{
		if ((ft_strncmp(instruction, possible_instructions[i],
					ft_strlen(instruction))) == 0)
			break ;
		i++;
	}
	if (i == 11)
		free_all_and_exit(instruction, stack_a, stack_b);
	return (i);
}

void	check_for_segfault(int instruction_number, char *instruction,
		t_stack **stack_a, t_stack **stack_b)
{
	bool	segfault;

	segfault = false;
	if (*stack_a == NULL && (instruction_number <= 2
			|| instruction_number >= 7))
		segfault = true;
	if (*stack_b == NULL && ((instruction_number >= 3
				&& instruction_number <= 6) || instruction_number >= 8))
		segfault = true;
	if (*stack_a != NULL && (*stack_a)->next == NULL)
	{
		if (instruction_number <= 2 || instruction_number >= 8)
			segfault = true;
	}
	if (*stack_b != NULL && (*stack_b)->next == NULL)
	{
		if (((instruction_number >= 4 && instruction_number <= 6)
				|| instruction_number >= 8))
			segfault = true;
	}
	if (segfault == true)
		free_all_and_exit(instruction, stack_a, stack_b);
}

void	execute_instruction(int instruction_number, t_stack **stack_a,
		t_stack **stack_b)
{
	if (instruction_number == 0)
		rotate(stack_a, 0);
	if (instruction_number == 1)
		reverse_rotate(stack_a, 0);
	if (instruction_number == 2)
		swap(stack_a, 0);
	if (instruction_number == 3)
		push(stack_a, stack_b, 'a', false);
	if (instruction_number == 4)
		rotate(stack_b, 0);
	if (instruction_number == 5)
		reverse_rotate(stack_b, 0);
	if (instruction_number == 6)
		swap(stack_b, 0);
	if (instruction_number == 7)
		push(stack_a, stack_b, 'b', false);
	if (instruction_number == 8)
		rr(stack_a, stack_b, false);
	if (instruction_number == 9)
		rrr(stack_a, stack_b, false);
	if (instruction_number == 10)
		ss(stack_a, stack_b, false);
}
