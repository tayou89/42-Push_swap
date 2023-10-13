/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_second_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:00:43 by tayou             #+#    #+#             */
/*   Updated: 2023/03/26 22:18:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stack_a(t_node **stack_a);

void	check_first_second_node(t_node **stack_a)
{
	int	stack_a_size;

	stack_a_size = get_stack_size(*stack_a);
	if (stack_a_size < 2)
		return ;
	if (check_stack_a(stack_a) == 1)
	{
		command_swap(*stack_a);
		ft_printf("sa\n");
	}
}

int	check_stack_a(t_node **stack_a)
{
	int	max_number;
	int	min_number;

	max_number = get_max_number(*stack_a);
	min_number = get_min_number(*stack_a);
	if ((*stack_a)->number == max_number &&
		(*stack_a)->next->number != min_number)
		return (1);
	if ((*stack_a)->number > (*stack_a)->next->number)
		return (1);
	return (0);
}
