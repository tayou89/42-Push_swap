/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_node_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:41:12 by tayou             #+#    #+#             */
/*   Updated: 2023/03/25 13:40:07 by tayou            ###   ########.fr       */
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
		if (stack == (void *) 0 || last_node == (void *) 0)
			return ((void *) 0);
	}
	if (stack->number < pivot)
		return (stack);
	else
		return (last_node);
}

void	put_under_pivot_to_top(t_node **stack, t_node **other, int pivot)
{
	t_node	*under_pivot_node;
	int		distance_to_top;
	int		distance_to_bottom;

	under_pivot_node = find_under_pivot_node(*stack, pivot);
	distance_to_top = get_distance_to_top(under_pivot_node);
	distance_to_bottom = get_distance_to_bottom(under_pivot_node);
	if (distance_to_top <= distance_to_bottom)
	{
		rotate_up_by_distance(stack, other, distance_to_top);
		print_ra_by_count(distance_to_top);
	}
	else
	{
		rotate_down_by_distance(stack, other, distance_to_bottom + 1);
		print_rra_by_count(distance_to_bottom + 1);
	}
}
