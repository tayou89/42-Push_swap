/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_second_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:00:43 by tayou             #+#    #+#             */
/*   Updated: 2023/03/21 07:11:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_both_stack(t_node **stack_a, t_node **stack_b);
int		check_stack_a(t_node **stack_a, t_node **stack_b);
int		check_stack_b(t_node **stack_b, t_node **stack_a);

void	check_first_second_node(t_node **stack_a, t_node **stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = get_stack_size(*stack_a);
	stack_b_size = get_stack_size(*stack_b);
	if (stack_a_size >= 2 && stack_b_size >= 2)
		check_both_stack(stack_a, stack_b);
	else if (stack_a_size >= 2 && stack_b_size < 2)
	{
		if (check_stack_a(stack_a, stack_b) == 1)
		{
			command_swap(*stack_a);
			ft_printf("sa\n");
		}
	}
	else if (stack_a_size < 2 && stack_b_size >= 2)
	{
		if (check_stack_b(stack_b, stack_a) == 1)
		{
			command_swap(*stack_b);
			ft_printf("sb\n");
		}
	}
}

void	check_both_stack(t_node **stack_a, t_node **stack_b)
{
	if (check_stack_a(stack_a, stack_b) == 1
		&& check_stack_b(stack_b, stack_a) == 1)
	{
		command_swap(*stack_a);
		command_swap(*stack_b);
		ft_printf("ss\n");
	}
	if (check_stack_a(stack_a, stack_b) == 1
		&& check_stack_b(stack_b, stack_a) != 1)
	{
		command_swap(*stack_a);
		ft_printf("sa\n");
	}
	if (check_stack_a(stack_a, stack_b) != 1
		&& check_stack_b(stack_b, stack_a) == 1)
	{
		command_swap(*stack_b);
		ft_printf("sb\n");
	}
}

int	check_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	max_number;
	int	min_number;

	max_number = get_max_number(*stack_a);
	min_number = get_min_number(*stack_a);
	if ((*stack_a)->number == max_number &&
		(*stack_a)->next->number == min_number)
	{
		command_rotate_up(stack_a, stack_b);
		ft_printf("ra\n");
	}
	if ((*stack_a)->number > (*stack_a)->next->number)
		return (1);
	return (0);
}

int	check_stack_b(t_node **stack_b, t_node **stack_a)
{
	int	max_number;
	int	min_number;

	max_number = get_max_number(*stack_b);
	min_number = get_min_number(*stack_b);
	if ((*stack_b)->number == min_number &&
		(*stack_b)->next->number == max_number)
	{
		command_rotate_up(stack_b, stack_a);
		ft_printf("rb\n");
	}
	if ((*stack_b)->number < (*stack_b)->next->number)
		return (1);
	return (0);
}
