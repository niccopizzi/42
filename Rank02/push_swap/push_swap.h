/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:41:10 by npizzi            #+#    #+#             */
/*   Updated: 2024/11/05 15:53:28 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				position;
	int				cost;
	bool			above_median;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

void				create_stack(int arguments, char *argv[]);

// STACK OPERATIONS

void				push(t_stack **stack_a, t_stack **stack_b, char mode,
						bool print);
void				swap(t_stack **stack, char mode);
void				rotate(t_stack **stack, char mode);
void				reverse_rotate(t_stack **stack, char mode);
void				rr(t_stack **stack_a, t_stack **stack_b, bool print);
void				rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void				ss(t_stack **stack_a, t_stack **stack_b, bool print);

// UTILS FUNCTIONS

t_stack				*find_max(t_stack *stack);
t_stack				*find_min(t_stack *stack);
int					stack_size(t_stack *stack);
bool				is_sorted(t_stack *stack);

// ALGO FUNCTIONS

void				merge(t_stack **stack_a, t_stack **stack_b);
void				three_sort_a(t_stack **stack_a);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);

// CHECKER FUNCTIONS

int					is_duplicate(int argc, char *argv[]);
int					is_input_valid(int argc, char *argv[]);

// INIT FUNCTIONS

t_stack				*create_node(int value);
t_stack				*initialize_stack(int arguments, char *argv[]);
void				ft_lstfree(t_stack **stack);
void				ft_lstadd_end(t_stack **head, t_stack *node);

#endif
