/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:14:02 by tayou             #+#    #+#             */
/*   Updated: 2023/03/23 15:19:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up_by_distance(t_node **to_rotate, t_node **other, int distance)
{
	int	i;

	i = 0;
	while (i < distance)
	{
		command_rotate_up(to_rotate, other);
		i++;
	}
}

void	rotate_down_by_distance(t_node **stack_b, t_node **stack_a, int distance)
{
	int	i;

	i = 0;
	while (i < distance)
	{
		command_rotate_down(stack_b, stack_a);
		i++;
	}
}
