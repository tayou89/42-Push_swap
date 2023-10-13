/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_until_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:00:35 by tayou             #+#    #+#             */
/*   Updated: 2023/03/25 01:00:48 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_when_size_is_small(t_node **stack_a, t_node **stack_b);
void	sort_when_size_is_big(t_node **stack_a, t_node **stack_b, int divisor);
int		check_stack_b_size_is_pivot(t_node *stack_b, int pivot_number);

void	sort_until_sorted(t_node **stack_a, t_node **stack_b, int divisor)
{
	int	stack_a_size;

	if (check_perfectly_sorted_stack_a(*stack_a) == 1)
		return ;
	stack_a_size = get_stack_size(*stack_a);
	if (stack_a_size <= divisor)
		sort_when_size_is_small(stack_a, stack_b);
	else
		sort_when_size_is_big(stack_a, stack_b, divisor);
	check_max_number_is_top(stack_b, stack_a);
}

void	sort_when_size_is_small(t_node **stack_a, t_node **stack_b)
{
	int	max_number;

	while (check_perfectly_sorted_stack_a(*stack_a) == 0
           || check_perfectly_sorted_stack_b(*stack_b) == 0)
	{
		max_number = get_max_number(*stack_a);
		check_first_second_node(stack_a);
		check_first_last_node(stack_a, stack_b, max_number + 1);
	}
}

void	sort_when_size_is_big(t_node **stack_a, t_node **stack_b, int divisor)
{
	t_node	*pivot;
	t_node	*pivot_head;
	int		pivot_number;

	pivot = get_pivot(*stack_a, divisor);
	pivot_head = pivot;
	while (check_perfectly_sorted_stack_a(*stack_a) == 0
		   || check_perfectly_sorted_stack_b(*stack_b) == 0)
	{
		pivot_number = get_pivot_number(pivot, *stack_a);
		check_first_last_node(stack_a, stack_b, pivot_number);
		if (check_stack_b_size_is_pivot(*stack_b, pivot_number) == 1)
			pivot = pivot->next;
	}
	free_list(pivot_head);
}

int	check_stack_b_size_is_pivot(t_node *stack_b, int pivot_number)
{
	int	stack_b_size;

	stack_b_size = get_stack_size(stack_b);
	if (stack_b_size == pivot_number)
		return (1);
	else
		return (0);
}
