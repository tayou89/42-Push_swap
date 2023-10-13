/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_node_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:41:12 by tayou             #+#    #+#             */
/*   Updated: 2023/03/23 20:06:58 by tayou            ###   ########.fr       */
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
	int 	max_number;

	max_number = get_max_number(stack);
	while (stack->number != max_number)
		stack = stack->next;
	max_node = stack;
	return (max_node);
}

t_node	*find_under_pivot_node(t_node *stack, int pivot)
{
	t_node	*last_node;
	
	last_node = find_last_node(stack);
	while (stack->number >= pivot && last_node->number >= pivot)
	{
		stack = stack->next;
		last_node = last_node->prev;
	}
	if (stack->number < pivot)
		return (stack);
	else
		return (last_node);
}
