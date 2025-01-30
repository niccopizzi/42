/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:10:52 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:12:44 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "../push_swap.h"

// SET FUNCTIONS

void	set_position(t_stack **stack);
void	set_target(t_stack **stack_a, t_stack **stack_b);
void	set_cost(t_stack **stack_a, t_stack **stack_b);
t_stack	*set_cheapest(t_stack **stack);

// ROTATION FUNCTIONS

void	bring_on_top(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
void	reverse_bring_on_top(t_stack **stack_a, t_stack **stack_b,
			t_stack *cheapest);
void	decide_rotation(t_stack **stack, int value, char mode,
			bool above_median);

#endif