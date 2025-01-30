/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:46:18 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:26:26 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	deal_with_instructions(t_stack **stack_a, t_stack **stack_b)
{
	char	*instruction;
	int		instruction_number;
	int		total_moves;

	total_moves = 0;
	instruction = get_next_line(0);
	while (instruction != NULL)
	{
		instruction_number = check_instruction(instruction, stack_a, stack_b);
		check_for_segfault(instruction_number, instruction, stack_a, stack_b);
		execute_instruction(instruction_number, stack_a, stack_b);
		total_moves++;
		free(instruction);
		instruction = get_next_line(0);
	}
	if (check_if_correct(stack_a, stack_b, total_moves) == false)
		write(STDERR_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
}

void	create_new_stack(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = initialize_stack(argc - 1, argv);
	if (stack_a == NULL)
	{
		ft_printf("Error in allocating memory\n");
		exit(EXIT_FAILURE);
	}
	stack_b = NULL;
	deal_with_instructions(&stack_a, &stack_b);
	ft_lstfree(&stack_a);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (1);
	if (is_input_valid(argc, argv) == false || is_duplicate(argc, argv) == true)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (2);
	}
	create_new_stack(argc, argv);
	return (0);
}
