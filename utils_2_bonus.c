/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:11:55 by tayou             #+#    #+#             */
/*   Updated: 2023/04/05 12:34:49 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

void	print_error_exit(t_node **stack_a, t_node **stack_b, char *command)
{
	ft_printf("Error\n");
	free_list_both(*stack_a, *stack_b);
	free(command);
	exit(1);
}
