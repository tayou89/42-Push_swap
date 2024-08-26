/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:17:42 by tayou             #+#    #+#             */
/*   Updated: 2023/04/01 22:12:22 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack != (void *) 0)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_max_number(t_node *stack)
{
	int	max_number;

	if (stack == (void *) 0)
		return (0);
	max_number = stack->number;
	while (stack->next != (void *) 0)
	{
		if (stack->next->number > max_number)
			max_number = stack->next->number;
		stack = stack->next;
	}
	return (max_number);
}

int	get_min_number(t_node *stack)
{
	int	min_number;

	if (stack == (void *) 0)
		return (0);
	min_number = stack->number;
	while (stack->next != (void *) 0)
	{
		if (stack->next->number < min_number)
			min_number = stack->next->number;
		stack = stack->next;
	}
	return (min_number);
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
