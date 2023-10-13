/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min_location.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:04:59 by tayou             #+#    #+#             */
/*   Updated: 2023/03/21 07:09:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_max_on_top(t_node **stack_b, t_node **stack_a, int index, int point);
void	put_min_on_top(t_node **stack_a, t_node **stack_b, int index, int point);

void	check_max_number_is_top(t_node **stack_b, t_node **stack_a)
{
	int	stack_size;
	int	middle_point;
	int	max_number_index;

	stack_size = get_stack_size(*stack_b);
	if (stack_size < 2)
		return ;
	middle_point = stack_size / 2;
	max_number_index = get_max_number_index(*stack_b);
	put_max_on_top(stack_b, stack_a, max_number_index, middle_point);
}

void	put_max_on_top(t_node **stack_b, t_node **stack_a, int index, int point)
{
	int	max_number;

	max_number = get_max_number(*stack_b);
	if (index > point)
	{
		while ((*stack_b)->number != max_number)
		{
			command_rotate_down(stack_b, stack_a);
			ft_printf("rrb\n");
		}
	}
	else
	{
		while ((*stack_b)->number != max_number)
		{
			command_rotate_up(stack_b, stack_a);
			ft_printf("rb\n");
		}
	}
}

void	check_min_number_is_top(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;
	int	middle_point;
	int	min_number_index;

	stack_size = get_stack_size(*stack_a);
	if (stack_size < 2)
		return ;
	middle_point = stack_size / 2;
	min_number_index = get_min_number_index(*stack_a);
	put_min_on_top(stack_a, stack_b, min_number_index, middle_point);
}

void	put_min_on_top(t_node **stack_a, t_node **stack_b, int index, int point)
{
	int	min_number;

	min_number = get_min_number(*stack_a);
	if (index > point)
	{
		while ((*stack_a)->number != min_number)
		{
			command_rotate_down(stack_a, stack_b);
			ft_printf("rra\n");
		}
	}
	else
	{
		while ((*stack_a)->number != min_number)
		{
			command_rotate_up(stack_a, stack_b);
			ft_printf("ra\n");
		}
	}
}
