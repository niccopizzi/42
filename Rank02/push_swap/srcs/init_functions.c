/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 08:57:11 by npizzi            #+#    #+#             */
/*   Updated: 2024/10/31 18:12:07 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->position = 0;
	node->cost = 0;
	node->above_median = false;
	node->target = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstfree(t_stack **stack)
{
	t_stack	*current;
	t_stack	*ptr;

	if (stack == NULL || *stack == NULL)
		return ;
	ptr = *stack;
	while (ptr != NULL)
	{
		current = ptr;
		ptr = ptr->next;
		free(current);
	}
}

void	ft_lstadd_end(t_stack **head, t_stack *node)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = node;
}

t_stack	*initialize_stack(int arguments, char *argv[])
{
	t_stack	*head;
	t_stack	*node;
	int		i;

	i = 1;
	head = create_node(ft_atoi(argv[1]));
	if (head == NULL)
		return (NULL);
	node = head;
	while (i++ < arguments)
	{
		node->next = create_node(ft_atoi(argv[i]));
		if (node->next == NULL)
		{
			ft_lstfree(&head);
			return (NULL);
		}
		ft_lstadd_end(&head, node);
		node = node->next;
	}
	node->next = NULL;
	return (head);
}
