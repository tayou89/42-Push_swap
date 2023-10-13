/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_everynode_to_stack_a.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:24:09 by tayou             #+#    #+#             */
/*   Updated: 2023/03/20 13:24:11 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_everynode_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_b) != (void *) 0)
	{
		command_push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}
