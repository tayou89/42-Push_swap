/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rough_sort_to_stack_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:06:39 by tayou             #+#    #+#             */
/*   Updated: 2023/03/24 23:16:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node_under_pivot(t_node **stack_a, t_node **stack_b, int pivot);
void	put_under_pivot_node_top(t_node **stack_a, t_node **stack_b, int pivot);
int	 	check_stack_top_is_max(t_node *stack);

void	rough_sort_to_stack_b(t_node **stack_a, t_node **stack_b, int pivot)
{
	int		stack_a_size;

	stack_a_size = get_stack_size(*stack_a);
	if (stack_a_size < 3)
		return ;
	else if (stack_a_size <= 100)
		pivot = pivot + stack_a_size / 3;
//	else if (stack_a_size <= 200)
//		pivot = pivot + stack_a_size / 7;
//	else if (stack_a_size <= 300)
//		pivot = pivot + stack_a_size / 6;
	else
		pivot = pivot + stack_a_size / 6;
//	ft_printf("pivot: %d\n", pivot);
	push_node_under_pivot(stack_a, stack_b, pivot);
//	ft_printf("-----------------stack_a------------------\n");
//	print_stack(*stack_a);
//	ft_printf("-----------------stack_b------------------\n");
//	print_stack(*stack_b);
	rough_sort_to_stack_b(stack_a, stack_b, pivot);
}

void	push_node_under_pivot(t_node **stack_a, t_node **stack_b, int pivot)
{
	int		stack_b_size;

	stack_b_size = get_stack_size(*stack_b);
	while (stack_b_size != pivot)
	{
		while ((*stack_a)->number >= pivot)
		{
			command_rotate_up(stack_a, stack_b);
			if (check_stack_top_is_max(*stack_b) != 1)
			{
				command_rotate_up(stack_b, stack_a);
				ft_printf("rr\n");
			}
			else
				ft_printf("ra\n");
		}
		/*
		if ((*stack_a)->next->number < (*stack_a)->number)
		{
			command_swap(*stack_a);
			if ((*stack_b)->next->number > (*stack_b)->number)
			{
				command_swap(*stack_b);
				ft_printf("ss\n");
			}
			else
				ft_printf("sa\n");
		}
		*/
		/*
		while ((*stack_a)->number >= pivot)
		{
			command_rotate_up(stack_a, stack_b);
			ft_printf("ra\n");
		}
		*/
//		put_under_pivot_node_top(stack_a, stack_b, pivot);
		command_push(stack_a, stack_b);
		ft_printf("pb\n");
		stack_b_size = get_stack_size(*stack_b);
	}
}

int	 check_stack_top_is_max(t_node *stack)
{
	int	max_number;

	if (stack == (void *) 0)
		return (1);
	max_number = get_max_number(stack);
	if (stack->number == max_number)
		return (1);
	else
		return (0);
}

void	put_under_pivot_node_top(t_node **stack_a, t_node **stack_b, int pivot)
{
	t_node	*under_pivot_node;
	int		distance_to_top;
	int		distance_to_bottom;

	under_pivot_node = find_under_pivot_node(*stack_a, pivot);
	distance_to_top = get_distance_to_top(under_pivot_node);
	distance_to_bottom = get_distance_to_bottom(under_pivot_node);
	if (distance_to_top <= distance_to_bottom)
	{
		rotate_up_by_distance(stack_a, stack_b, distance_to_top);
		print_ra_by_count(distance_to_top);
	}
	else
	{
		rotate_down_by_distance(stack_a, stack_b, distance_to_bottom + 1);
		print_rra_by_count(distance_to_bottom + 1);
	}
}
