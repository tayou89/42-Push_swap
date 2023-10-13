/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:42:37 by tayou             #+#    #+#             */
/*   Updated: 2023/03/31 14:13:49 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
