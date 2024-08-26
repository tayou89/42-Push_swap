/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:01:06 by tayou             #+#    #+#             */
/*   Updated: 2023/04/05 12:13:28 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
