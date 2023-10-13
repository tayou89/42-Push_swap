/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:26:18 by tayou             #+#    #+#             */
/*   Updated: 2023/04/05 11:48:44 by tayou            ###   ########.fr       */
/*   Updated: 2023/04/02 03:12:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_stack_b_pivot(t_node *pivot);
void	rotate_and_push(t_node **a, t_node **b, t_node *pivot_b);
t_node	*get_right_position(t_node *stack_a, int number);
void	free_all_and_exit(t_node **stack_a, t_node **stack_b, t_node **pivot);

void	sort_to_stack_a(t_node **stack_a, t_node **stack_b, t_node *pivot)
{
	t_node	*stack_b_pivot;
	t_node	*pivot_head;

	pivot_head = pivot;
	while (pivot->next != (void *) 0)
	{
		stack_b_pivot = get_stack_b_pivot(pivot);
		if (stack_b_pivot == (void *) 0)
			free_all_and_exit(stack_a, stack_b, &pivot_head);
		rotate_and_push(stack_a, stack_b, stack_b_pivot);
		pivot = pivot->next;
		free_list(stack_b_pivot);
	}
}

t_node	*get_stack_b_pivot(t_node *pivot)
{
	t_node	*stack_b_pivot;
	t_node	*new_node;
	int		new_pivot_number;
	int		pivot_gap;
	int		remain_gap;

	stack_b_pivot = get_new_node(pivot->next->number);
	if (stack_b_pivot == (void *) 0)
		return ((void *) 0);
	pivot_gap = pivot->number - pivot->next->number;
	remain_gap = pivot_gap;
	while (remain_gap > 20)
	{
		new_pivot_number = stack_b_pivot->number + (pivot_gap / 5);
		new_node = get_new_node(new_pivot_number);
		if (new_node == (void *) 0)
		{
			free_list(stack_b_pivot);
			return ((void *) 0);
		}
		stack_b_pivot = add_node_front(stack_b_pivot, new_node);
		remain_gap = pivot->number - stack_b_pivot->number;
	}
	return (stack_b_pivot);
}

void	rotate_and_push(t_node **a, t_node **b, t_node *pivot_b)
{
	t_node	*over_pivot;
	t_node	*right_position;

	while (pivot_b != (void *) 0)
	{
		over_pivot = find_over_pivot_node(*b, pivot_b->number);
		while (over_pivot != (void *) 0)
		{
			right_position = get_right_position(*a, over_pivot->number);
			rotate_to_top(a, b, right_position, over_pivot);
			push_top_to_stack_a(b, a);
			over_pivot = find_over_pivot_node(*b, pivot_b->number);
		}
		pivot_b = pivot_b->next;
	}
}

t_node	*get_right_position(t_node *stack_a, int number)
{
	t_node	*stack_a_head;
	t_node	*min_node;

	min_node = find_min_node(stack_a);
	if (number < min_node->number)
		return (min_node);
	stack_a_head = stack_a;
	while (stack_a->next != (void *) 0)
	{
		if (number > stack_a->number && number < stack_a->next->number)
			return (stack_a->next);
		stack_a = stack_a->next;
	}
	return (stack_a_head);
}

void	free_all_and_exit(t_node **stack_a, t_node **stack_b, t_node **pivot)
{
	free_list_both(*stack_a, *stack_b);
	free_list(*pivot);
	exit(1);
}
