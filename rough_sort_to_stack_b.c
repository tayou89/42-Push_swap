/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rough_sort_to_stack_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:06:39 by tayou             #+#    #+#             */
/*   Updated: 2023/03/25 13:35:24 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//int		get_pivot_number(t_node *pivot);
t_node	*get_pivot(t_node *pivot, int pivot_number);
void	push_node_under_pivot(t_node **stack_a, t_node **stack_b, int pivot);
void	put_under_pivot_node_top(t_node **stack_a, t_node **stack_b, int pivot);
int	 	check_stack_top_is_max(t_node *stack);

void	rough_sort_to_stack_b(t_node **stack_a, t_node **stack_b, t_node **pivot)
{
	int		stack_a_size;
	int		pivot_number;
//	t_node	*last_pivot;

	stack_a_size = get_stack_size(*stack_a);
//	last_pivot = find_last_node(*pivot);
	pivot_number = (*pivot)->number;
	if (stack_a_size < 3)
		return ;
	else if (stack_a_size <= 100)
		pivot_number = pivot_number + stack_a_size / 3;
	else
		pivot_number = pivot_number + stack_a_size / 7;
	*pivot = get_pivot(*pivot, pivot_number);
	if (*pivot == (void *) 0)
	{
		free_list_both(*stack_a, *stack_b);
		return ;
	}
//	last_pivot = find_last_node(*pivot);
	push_node_under_pivot(stack_a, stack_b, (*pivot)->number);
	rough_sort_to_stack_b(stack_a, stack_b, pivot);
}
/*
int	get_pivot_number(t_node *pivot)
{
	int	 pivot_number;

	if (pivot == (void *) 0)
		pivot_number = 0;
	else
		pivot_number = pivot->number;
	return (pivot_number);
}
*/
t_node	*get_pivot(t_node *pivot, int pivot_number)
{
	t_node	*new_node;

	if (pivot == (void *) 0)
	{
		pivot = get_new_node(pivot_number);
		if (pivot == (void *) 0)
			return ((void *) 0);
	}
	else
	{
		new_node = get_new_node(pivot_number);
		if (new_node == (void *) 0)
		{
			free_list(pivot);
			return ((void *) 0);
		}
		pivot = add_node_front(pivot, new_node);
	}
	return (pivot);
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
