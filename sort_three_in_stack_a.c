/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_in_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:24:27 by tayou             #+#    #+#             */
/*   Updated: 2023/03/27 23:36:56 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_not_sorted_point(t_node *stack);
void		put_not_sorted_top(t_node **stack_a, t_node **stack_b, int point);
void		swap_stack_a(t_node **stack_a);
void		rotate_back_to_sort(t_node **stack_a, t_node **stack_b, int point);

void	sort_three_in_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	not_sorted_point;

	not_sorted_point = get_not_sorted_point(*stack_a);
	put_not_sorted_top(stack_a, stack_b, not_sorted_point);
	swap_stack_a(stack_a);
	rotate_back_to_sort(stack_a, stack_b, not_sorted_point);
}

static int	get_not_sorted_point(t_node *stack)
{
	int	not_sorted_point;
	int	i;

	i = 0;
	while (stack->number < stack->next->number)
	{
		i++;
		stack = stack->next;
	}
	not_sorted_point = i;
	return (not_sorted_point);
}

void	put_not_sorted_top(t_node **stack_a, t_node **stack_b, int point)
{
	int	i;

	i = 0;
	while (i < point)
	{
		command_rotate_up(stack_a, stack_b);
		command_rotate_up(stack_b, stack_a);
		ft_printf("rr\n");
		i++;
	}
}

void	swap_stack_a(t_node **stack_a)
{
	command_swap(*stack_a);
	ft_printf("sa\n");
}

void	rotate_back_to_sort(t_node **stack_a, t_node **stack_b, int point)
{
	int	i;

	i = 0;
	while (i < point)
	{
		command_rotate_down(stack_a, stack_b);
		ft_printf("rra\n");
		i++;
	}
}
