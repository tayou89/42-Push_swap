/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_last_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:16:28 by tayou             #+#    #+#             */
/*   Updated: 2023/04/01 22:07:29 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_right_position(t_node *stack_b, int number);
int		check_right_position(t_node *stack_b, int min, int max, int number);
void	rotate_to_position(t_node **stack_b, int position, t_node **stack_a);

void	check_first_last_node(t_node **stack_a, t_node **stack_b)
{
	t_node	*last_node;
	int		right_position;

	last_node = find_last_node(*stack_a);
	if ((*stack_a)->number < last_node->number)
	{
		right_position = find_right_position(*stack_b, (*stack_a)->number);
		rotate_to_position(stack_b, right_position, stack_a);
		command_push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else
	{
		command_rotate_down(stack_a, stack_b);
		ft_printf("rra\n");
	}
}

int	find_right_position(t_node *stack_b, int number)
{
	int	right_position;
	int	min;
	int	max;

	if (stack_b == (void *) 0)
		return (0);
	min = get_min_number(stack_b);
	max = get_max_number(stack_b);
	right_position = 1;
	while (stack_b->next != (void *) 0)
	{
		if (check_right_position(stack_b, min, max, number) == 1)
			return (right_position);
		right_position++;
		stack_b = stack_b->next;
	}
	right_position = 0;
	return (right_position);
}

int	check_right_position(t_node *stack_b, int min, int max, int number)
{
	if (number < min || number > max)
	{
		if (stack_b->number == min)
			return (1);
	}
	else
	{
		if (number < stack_b->number && number > stack_b->next->number)
			return (1);
	}
	return (0);
}

void	rotate_to_position(t_node **stack_b, int position, t_node **stack_a)
{
	int	stack_size;
	int	i;

	if (position == 0)
		return ;
	stack_size = get_stack_size(*stack_b);
	i = 0;
	if (position <= (stack_size / 2))
	{
		while (i < position)
		{
			command_rotate_up(stack_b, stack_a);
			ft_printf("rb\n");
			i++;
		}
	}
	else
	{
		while (i < stack_size - position)
		{
			command_rotate_down(stack_b, stack_a);
			ft_printf("rrb\n");
			i++;
		}
	}
}
