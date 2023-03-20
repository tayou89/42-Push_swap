/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_last_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:28 by tayou             #+#    #+#             */
/*   Updated: 2023/03/21 04:47:29 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_first_last_node(t_node **stack_a, t_node **stack_b)
{
	t_node	*last_node;

	last_node = find_last_node(*stack_a);
	if (last_node->number > (*stack_a)->number)
	{
		command_push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else
	{
		command_rotate_down(stack_a, stack_b);
		ft_printf("rra\n");
	}
}
