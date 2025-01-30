/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:23:52 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:12:15 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	if (print == true)
		ft_printf("rr\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	reverse_rotate(stack_a, 0);
	reverse_rotate(stack_b, 0);
	if (print == true)
		ft_printf("rrr\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool print)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	if (print == true)
		ft_printf("ss\n");
}
