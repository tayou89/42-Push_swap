/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size_under_thirty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:05:42 by tayou             #+#    #+#             */
/*   Updated: 2023/03/27 23:38:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_until_sorted(t_node **stack_a, t_node **stack_b);

void	sort_under_thirty(t_node **stack_a, t_node **stack_b)
{
	sort_until_sorted(stack_a, stack_b);
	check_min_number_is_top(stack_a, stack_b);
	check_max_number_is_top(stack_b, stack_a);
	if (check_perfectly_sorted_stack_b(*stack_b) == 1)
		push_everynode_to_stack_a(stack_b, stack_a);
}

void	sort_until_sorted(t_node **stack_a, t_node **stack_b)
{
	if (check_perfectly_sorted_stack_a(*stack_a) == 1)
		return ;
	while (check_perfectly_sorted_stack_a(*stack_a) != 1
		|| check_perfectly_sorted_stack_b(*stack_b) != 1)
	{
		check_first_second_node(stack_a);
		check_first_last_node(stack_a, stack_b);
	}
}
