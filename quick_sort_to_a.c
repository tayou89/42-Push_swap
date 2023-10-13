/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_to_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:19:37 by tayou             #+#    #+#             */
/*   Updated: 2023/03/27 23:35:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		confirm_stack_b_pivot(t_node *pivot_first, int stack_b_pivot);
void	push_over_pivot_node(t_node **stack_b, t_node **stack_a, int pivot);
void	rotate_over_pivot_to_top(t_node **stack_b, t_node **stack_a, int pivot);

void	quick_sort_to_a(t_node **stack_a, t_node **stack_b, t_node *pivot)
{
	t_node	*pivot_first;
	t_node	*pivot_last;
	int		stack_b_pivot;

	while (pivot->next != (void *) 0)
	{
		pivot_first = pivot;
		pivot_last = pivot->next;
		while (pivot_first->number != pivot_last->number)
		{
			stack_b_pivot = (pivot_first->number + pivot_last->number) / 2;
			stack_b_pivot = confirm_stack_b_pivot(pivot_first, stack_b_pivot);
			push_over_pivot_node(stack_b, stack_a, stack_b_pivot);
			check_first_second_node(stack_a);
			pivot_first->number = stack_b_pivot;
			if (check_perfectly_sorted_stack_a(*stack_a) != 1)
				sort_three_in_stack_a(stack_a, stack_b);
		}
		pivot = pivot->next;
	}
}

int	confirm_stack_b_pivot(t_node *pivot_first, int stack_b_pivot)
{
	while (pivot_first->number - stack_b_pivot > 3)
		stack_b_pivot = (pivot_first->number + stack_b_pivot) / 2;
	return (stack_b_pivot);
}

void	push_over_pivot_node(t_node **stack_b, t_node **stack_a, int pivot)
{
	t_node	*over_pivot_node;
	int		count;

	if ((*stack_b) == (void *) 0)
		return ;
	count = 0;
	over_pivot_node = find_over_pivot_node(*stack_b, pivot);
	while (over_pivot_node != (void *) 0)
	{
		rotate_over_pivot_to_top(stack_b, stack_a, pivot);
		push_top_to_stack_a(stack_b, stack_a);
		count++;
		if (count <= 2)
			check_first_second_node(stack_a);
		if ((*stack_b) == (void *) 0)
			over_pivot_node = (void *) 0;
		else
			over_pivot_node = find_over_pivot_node(*stack_b, pivot);
	}
}

void	rotate_over_pivot_to_top(t_node **stack_b, t_node **stack_a, int pivot)
{
	t_node	*over_pivot_node;
	int		distance_to_top;
	int		distance_to_bottom;

	over_pivot_node = find_over_pivot_node(*stack_b, pivot);
	distance_to_top = get_distance_to_top(over_pivot_node);
	distance_to_bottom = get_distance_to_bottom(over_pivot_node);
	if (distance_to_top <= distance_to_bottom)
		rotate_up_by_count(stack_b, stack_a, distance_to_top);
	else
		rotate_down_by_count(stack_b, stack_a, distance_to_bottom + 1);
}
