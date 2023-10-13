/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:17:42 by tayou             #+#    #+#             */
/*   Updated: 2023/03/25 00:39:37 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != (void *) 0)
	{
		ft_printf("stack[%d]: %d\n", i, stack->number);
		i++;
		stack = stack->next;
	}
}

int	get_max_number_index(t_node *stack)
{
	int	max_number_index;
	int	max_number;
	int	i;

	max_number = get_max_number(stack);
	i = 0;
	while (stack->number != max_number)
	{
		stack = stack->next;
		i++;
	}
	max_number_index = i;
	return (max_number_index);
}

int	get_min_number_index(t_node *stack)
{
	int	min_number;
	int	min_number_index;
	int	i;

	min_number = get_min_number(stack);
	i = 0;
	while (stack->number != min_number)
	{
		stack = stack->next;
		i++;
	}
	min_number_index = i;
	return (min_number_index);
}
/*
int	get_pivot_number(t_node *pivot, t_node *stack_a)
{
	int	pivot_number;
	int	max_number;

	max_number = get_max_number(stack_a);
	if (pivot == (void *) 0)
		pivot_number = max_number + 1;
	else
		pivot_number = pivot->number;
	return (pivot_number);
}
*/
int	get_distance_to_top(t_node *node)
{
	int distance;
	int	i;

	i = 0;
	while (node->prev != (void *) 0)
	{
		node = node->prev;
		i++;
	}
	distance = i;
	return (distance);
}

int	 get_distance_to_bottom(t_node *node)
{
	int	distance;
	int	i;

	i = 0;
	while (node->next != (void *) 0)
	{
		node = node->next;
		i++;
	}
	distance = i;
	return (distance);
}
