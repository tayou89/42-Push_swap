/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_max_to_stack_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:10:13 by tayou             #+#    #+#             */
/*   Updated: 2023/03/26 23:19:18 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_a(t_node **stack_b, t_node **stack_a);
void	swap_stack_b_then_push_to_stack_a(t_node **stack_b, t_node **stack_a);
void	rotate_stack_b_then_push_to_stack_a(t_node **stack_b, t_node **stack_a);
void	rotate_max_to_top(t_node **stack_b, t_node **stack_a, int max_number);

void	push_max_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	max_number;

	max_number = get_max_number(*stack_b);
	while ((*stack_b) != (void *) 0)
	{
		/*
		if ((*stack_b)->number < (*stack_b)->next->number)
		{
			command_swap(*stack_b);
			ft_printf("sb\n");
		}
		*/
		if ((*stack_b)->number == max_number)
			push_to_stack_a(stack_b, stack_a);
		else if ((*stack_b)->next->number == max_number)
			swap_stack_b_then_push_to_stack_a(stack_b, stack_a);
		else
			rotate_stack_b_then_push_to_stack_a(stack_b, stack_a);
		max_number--;
	}
}

void	push_to_stack_a(t_node **stack_b, t_node **stack_a)
{
	command_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	swap_stack_b_then_push_to_stack_a(t_node **stack_b, t_node **stack_a)
{
	command_swap(*stack_b);
	ft_printf("sb\n");
	command_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	rotate_stack_b_then_push_to_stack_a(t_node **stack_b, t_node **stack_a)
{
	t_node	*max_node;
	int		distance_to_top;
	int		distance_to_bottom;

	max_node = find_max_node(*stack_b);
	distance_to_top = get_distance_to_top(max_node);
	distance_to_bottom = get_distance_to_bottom(max_node);
	if (distance_to_top <= distance_to_bottom)
	{
		rotate_up_by_distance(stack_b, stack_a, distance_to_top);
		print_rb_by_count(distance_to_top);
		push_to_stack_a(stack_b, stack_a);
	}
	else
	{
		rotate_down_by_distance(stack_b, stack_a, distance_to_bottom + 1);
		print_rrb_by_count(distance_to_bottom + 1);
		push_to_stack_a(stack_b, stack_a);
	}
}
