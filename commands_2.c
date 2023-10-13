/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:14:02 by tayou             #+#    #+#             */
/*   Updated: 2023/04/01 22:33:08 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_everynode_to_stack_a(t_node **stack_from, t_node **stack_to)
{
	while ((*stack_from) != (void *) 0)
	{
		command_push(stack_from, stack_to);
		ft_printf("pa\n");
	}
}

void	push_top_to_stack_a(t_node **stack_from, t_node **stack_to)
{
	command_push(stack_from, stack_to);
	ft_printf("pa\n");
}

void	command_swap_both(t_node *stack_a, t_node *stack_b)
{
	command_swap(stack_a);
	command_swap(stack_b);
}

void	command_rotate_up_both(t_node **stack_a, t_node **stack_b)
{
	command_rotate_up(stack_a, stack_b);
	command_rotate_up(stack_b, stack_a);
}

void	command_rotate_down_both(t_node **stack_a, t_node **stack_b)
{
	command_rotate_down(stack_a, stack_b);
	command_rotate_down(stack_b, stack_a);
}
