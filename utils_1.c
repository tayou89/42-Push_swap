/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:59:52 by tayou             #+#    #+#             */
/*   Updated: 2023/03/20 12:23:23 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

void	pass_space(char *str, int *i)
{
	while (ft_isspace(str[*i]) == 1)
		(*i)++;
}

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

	min_number = stack->number;
	while (stack->next != (void *) 0)
	{
		if (stack->next->number < min_number)
			min_number = stack->next->number;
		stack = stack->next;
	}
	return (min_number);
}
