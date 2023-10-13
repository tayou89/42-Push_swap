/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_node_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:41:12 by tayou             #+#    #+#             */
/*   Updated: 2023/04/01 18:50:15 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *stack)
{
	if (stack == (void *) 0)
		return (stack);
	while (stack->next != (void *) 0)
		stack = stack->next;
	return (stack);
}

t_node	*find_max_node(t_node *stack)
{
	t_node	*max_node;
	int		max_number;

	max_number = get_max_number(stack);
	while (stack->number != max_number)
		stack = stack->next;
	max_node = stack;
	return (max_node);
}

t_node	*find_min_node(t_node *stack)
{
	t_node	*min_node;
	int		min_number;

	min_number = get_min_number(stack);
	while (stack->number != min_number)
		stack = stack->next;
	min_node = stack;
	return (min_node);
}

t_node	*find_over_pivot_node(t_node *stack, int pivot)
{
	t_node	*last_node;

	if (stack == (void *) 0)
		return ((void *) 0);
	last_node = find_last_node(stack);
	while (stack->number <= pivot && last_node->number <= pivot)
	{
		stack = stack->next;
		last_node = last_node->prev;
		if (stack == (void *) 0 || last_node == (void *) 0)
			return ((void *) 0);
	}
	if (last_node->number > pivot)
		return (last_node);
	else
		return (stack);
}
