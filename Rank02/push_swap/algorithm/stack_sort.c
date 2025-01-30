/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:34:19 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:25:24 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	send_cheapest(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest)
{
	int	result;

	result = cheapest->above_median + cheapest->target->above_median;
	if (result == 2)
		reverse_bring_on_top(stack_a, stack_b, cheapest);
	else if (result == 0)
		bring_on_top(stack_a, stack_b, cheapest);
	else if (result == 1)
	{
		decide_rotation(stack_a, cheapest->target->value, 'a',
			cheapest->target->above_median);
		decide_rotation(stack_b, cheapest->value, 'b', cheapest->above_median);
	}
	push(stack_a, stack_b, 'a', true);
}

void	merge(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	t_stack	*min;

	while (*stack_b != NULL)
	{
		set_position(stack_a);
		set_position(stack_b);
		set_target(stack_a, stack_b);
		set_cost(stack_a, stack_b);
		cheapest = set_cheapest(stack_b);
		send_cheapest(stack_a, stack_b, cheapest);
	}
	min = find_min(*stack_a);
	if ((*stack_a)->value != min->value)
		decide_rotation(stack_a, min->value, 'a', min->above_median);
}

void	three_sort_a(t_stack **stack_a)
{
	t_stack	*max;

	max = find_max((*stack_a));
	if ((*stack_a)->value == max->value)
		rotate(stack_a, 'a');
	else if ((*stack_a)->next->value == max->value)
		reverse_rotate(stack_a, 'a');
	if ((*stack_a)->value > (*stack_a)->next->value)
		swap(stack_a, 'a');
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	size_a = stack_size(*stack_a);
	while (size_a != 3)
	{
		push(stack_a, stack_b, 'b', true);
		size_a--;
	}
	three_sort_a(stack_a);
	merge(stack_a, stack_b);
}
