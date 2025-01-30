/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:26:49 by niccol            #+#    #+#             */
/*   Updated: 2024/10/31 18:12:12 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack, char mode)
{
	int	temp;

	if (stack == NULL || *stack == NULL)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	if (mode != 0)
		ft_printf("s%c\n", mode);
}

void	push(t_stack **stack_a, t_stack **stack_b, char mode, bool print)
{
	t_stack	*top_of_stack;

	if (mode == 'a' && *stack_b != NULL)
	{
		top_of_stack = *stack_b;
		*stack_b = (*stack_b)->next;
		top_of_stack->next = *stack_a;
		*stack_a = top_of_stack;
		if (print == true)
			ft_printf("pa\n");
	}
	if (mode == 'b' && *stack_a != NULL)
	{
		top_of_stack = *stack_a;
		*stack_a = (*stack_a)->next;
		top_of_stack->next = *stack_b;
		*stack_b = top_of_stack;
		if (print == true)
			ft_printf("pb\n");
	}
}

void	rotate(t_stack **stack, char mode)
{
	t_stack	*ptr;
	int		temp;

	if (stack == NULL || *stack == NULL)
		return ;
	temp = (*stack)->value;
	ptr = *stack;
	while (ptr->next != NULL)
	{
		ptr->value = ptr->next->value;
		ptr = ptr->next;
	}
	ptr->value = temp;
	if (mode != 0)
		ft_printf("r%c\n", mode);
}

void	reverse_rotate(t_stack **stack, char mode)
{
	t_stack	*ptr;
	int		current_value;
	int		next_value;

	if (stack == NULL || *stack == NULL)
		return ;
	ptr = (*stack);
	current_value = ptr->value;
	while (ptr->next != NULL)
	{
		next_value = ptr->next->value;
		ptr->next->value = current_value;
		current_value = next_value;
		ptr = ptr->next;
	}
	(*stack)->value = current_value;
	if (mode != 0)
		ft_printf("rr%c\n", mode);
}
