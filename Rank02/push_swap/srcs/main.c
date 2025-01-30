/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:41:52 by npizzi            #+#    #+#             */
/*   Updated: 2024/11/05 15:55:05 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	create_stack(int arguments, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = initialize_stack(arguments - 1, argv);
	if (stack_a == NULL)
	{
		ft_printf("Error in allocating memory\n");
		exit(EXIT_FAILURE);
	}
	stack_b = NULL;
	if (is_sorted(stack_a) == true)
	{
		ft_lstfree(&stack_a);
		return ;
	}
	if (arguments == 3)
	{
		if (stack_a->value > stack_a->next->value)
			swap(&stack_a, 'a');
	}
	if (arguments == 4)
		three_sort_a(&stack_a);
	if (arguments > 4)
		sort_stack(&stack_a, &stack_b);
	ft_lstfree(&stack_a);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		return (0);
	if (argc == 2 && is_input_valid(argc, argv) == false)
	{
		ft_printf(MODE_BOLD ANSI_COLOR_RED
			"Error\n" ANSI_MODE_RESET);
		return (1);
	}
	if (is_duplicate(argc, argv) == true)
	{
		ft_printf(MODE_BOLD ANSI_COLOR_RED
			"Error\n" ANSI_MODE_RESET);
		return (2);
	}
	if (is_input_valid(argc, argv) == false)
	{
		ft_printf(MODE_BOLD ANSI_COLOR_RED "Error\n" ANSI_MODE_RESET);
		return (3);
	}
	create_stack(argc, argv);
	return (0);
}
