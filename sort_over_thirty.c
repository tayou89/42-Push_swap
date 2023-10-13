/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_over_thirty.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:11:22 by tayou             #+#    #+#             */
/*   Updated: 2023/04/01 22:13:33 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*initialize_pivot(t_node **stack_a, t_node **stack_b);

void	sort_over_thirty(t_node **stack_a, t_node **stack_b)
{
	t_node	*pivot;

	pivot = initialize_pivot(stack_a, stack_b);
	rough_sort_to_b(stack_a, stack_b, &pivot);
	check_first_second_node(stack_a);
	sort_to_stack_a(stack_a, stack_b, pivot);
	check_min_number_is_top(stack_a, stack_b);
	push_everynode_to_stack_a(stack_b, stack_a);
	free_list(pivot);
}

t_node	*initialize_pivot(t_node **stack_a, t_node **stack_b)
{
	t_node	*pivot;

	pivot = get_new_node(0);
	if (pivot == (void *) 0)
	{
		free_list_both(*stack_a, *stack_b);
		exit(1);
	}
	return (pivot);
}
