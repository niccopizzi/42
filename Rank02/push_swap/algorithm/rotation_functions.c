/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:15:08 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:12:47 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	bring_on_top(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	int	target_value;
	int	cheapest_value;

	target_value = cheapest->target->value;
	cheapest_value = cheapest->value;
	while ((*stack_a)->value != target_value
		&& (*stack_b)->value != cheapest_value)
		rr(stack_a, stack_b, true);
	if ((*stack_a)->value != target_value)
	{
		while ((*stack_a)->value != target_value)
			rotate(stack_a, 'a');
	}
	if ((*stack_b)->value != cheapest_value)
	{
		while ((*stack_b)->value != cheapest_value)
			rotate(stack_b, 'b');
	}
}

void	reverse_bring_on_top(t_stack **stack_a, t_stack **stack_b,
		t_stack *cheapest)
{
	int	target_value;
	int	cheapest_value;

	target_value = cheapest->target->value;
	cheapest_value = cheapest->value;
	while ((*stack_a)->value != target_value
		&& (*stack_b)->value != cheapest_value)
		rrr(stack_a, stack_b, true);
	if ((*stack_a)->value != target_value)
	{
		while ((*stack_a)->value != target_value)
			reverse_rotate(stack_a, 'a');
	}
	if ((*stack_b)->value != cheapest_value)
	{
		while ((*stack_b)->value != cheapest_value)
			reverse_rotate(stack_b, 'b');
	}
}

void	decide_rotation(t_stack **stack, int value, char mode,
		bool above_median)
{
	if (above_median == true)
	{
		while ((*stack)->value != value)
			reverse_rotate(stack, mode);
	}
	else
	{
		while ((*stack)->value != value)
			rotate(stack, mode);
	}
}
