/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:14:02 by tayou             #+#    #+#             */
/*   Updated: 2023/03/28 15:18:21 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up_by_count(t_node **to_rotate, t_node **other, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		command_rotate_up(to_rotate, other);
		ft_printf("rb\n");
		i++;
	}
}

void	rotate_down_by_count(t_node **to_rotate, t_node **other, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		command_rotate_down(to_rotate, other);
		ft_printf("rrb\n");
		i++;
	}
}

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
