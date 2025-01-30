/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:10:25 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:24:26 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	set_position(t_stack **stack)
{
	int		position;
	int		stack_len;
	t_stack	*ptr;

	ptr = *stack;
	stack_len = stack_size(*stack);
	position = 0;
	while (ptr != NULL)
	{
		ptr->position = position;
		if (position >= stack_len / 2)
			ptr->above_median = true;
		else
			ptr->above_median = false;
		position++;
		ptr = ptr->next;
	}
}

void	set_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	t_stack	*ptr_a;
	t_stack	*ptr_b;
	long	target_value;

	ptr_b = *stack_b;
	while (ptr_b != NULL)
	{
		target_value = __LONG_MAX__;
		ptr_a = *stack_a;
		target = *stack_a;
		while (ptr_a != NULL)
		{
			if ((ptr_a->value > ptr_b->value && ptr_a->value < target_value))
			{
				target = ptr_a;
				target_value = target->value;
			}
			ptr_a = ptr_a->next;
		}
		if (target_value == __LONG_MAX__)
			target = find_min(*stack_a);
		ptr_b->target = target;
		ptr_b = ptr_b->next;
	}
}

void	set_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		len_a;
	int		len_b;
	t_stack	*ptr_b;

	len_a = stack_size(*stack_a);
	len_b = stack_size(*stack_b);
	ptr_b = *stack_b;
	while (ptr_b != NULL)
	{
		if (ptr_b->above_median == true && ptr_b->target->above_median == true)
			ptr_b->cost = ft_max(len_a - ptr_b->target->position, len_b
					- ptr_b->position);
		else if (ptr_b->above_median == false
			&& ptr_b->target->above_median == false)
			ptr_b->cost = ft_max(ptr_b->target->position, ptr_b->position);
		else
		{
			ptr_b->cost = ft_min(ptr_b->target->position, len_a
					- ptr_b->target->position);
			ptr_b->cost += ft_min(ptr_b->position, len_b - ptr_b->position);
		}
		ptr_b = ptr_b->next;
	}
}

t_stack	*set_cheapest(t_stack **stack)
{
	int		cheapest;
	t_stack	*ptr;

	ptr = *stack;
	cheapest = ptr->cost;
	while (ptr != NULL)
	{
		if (ptr->cost < cheapest)
			cheapest = ptr->cost;
		ptr = ptr->next;
	}
	ptr = *stack;
	while (ptr != NULL)
	{
		if (ptr->cost == cheapest)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
