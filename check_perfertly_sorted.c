/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_perfertly_sorted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:56:46 by tayou             #+#    #+#             */
/*   Updated: 2023/03/21 06:51:44 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_perfectly_sorted_stack_a(t_node *stack)
{
	int		min_number;
	int		max_number;
	t_node	*stack_head;

	stack_head = stack;
	min_number = get_min_number(stack);
	max_number = get_max_number(stack);
	while (stack->next != (void *) 0)
	{
		if (stack->number == max_number && stack->next->number != min_number)
			return (0);
		if (stack->number != max_number &&
			stack->next->number != stack->number + 1)
			return (0);
		stack = stack->next;
	}
	if (stack->number == max_number && stack_head->number != min_number)
		return (0);
	if (stack->number != max_number && stack_head->number != stack->number + 1)
		return (0);
	return (1);
}

int	check_perfectly_sorted_stack_b(t_node *stack)
{
	int 	min_number;
	int		max_number;
	t_node	*stack_head;

	if (stack == (void *) 0)
		return (1);
	stack_head = stack;
	min_number = get_min_number(stack);
	max_number = get_max_number(stack);
	while (stack->next != (void *) 0)
	{
		if (stack->number == min_number && stack->next->number != max_number)
			return (0);
		if (stack->number != min_number && stack->next->number != stack->number - 1)
			return (0);
		stack = stack->next;
	}
	if (stack->number == min_number && stack_head->number != max_number)
		return (0);
	if (stack->number != min_number && stack_head->number != stack->number - 1)
		return (0);
	return (1);
}
