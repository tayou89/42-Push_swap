/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_sorted_stack_b.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:35:40 by tayou             #+#    #+#             */
/*   Updated: 2023/03/21 05:41:37 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_not_sorted_point(t_node *stack_b);
int		compare_with_next_node(t_node *node, t_node *stack);
void	sort_stack_b(t_node **stack_b, t_node **stack_a, int not_sorted_point);

void	check_if_sorted_stack_b(t_node **stack_b, t_node **stack_a)
{
	int		size;
	int		not_sorted_point;

	size = get_stack_size(*stack_b);
	if (size < 3)
		return ;
	not_sorted_point = get_not_sorted_point(*stack_b);
	if (not_sorted_point > 0)
		sort_stack_b(stack_b, stack_a, not_sorted_point);
}

int	get_not_sorted_point(t_node *stack_b)
{
	t_node	*copy_stack;
	int		i;

	copy_stack = stack_b;
	i = 0;
	while (copy_stack != (void *) 0)
	{
		if (compare_with_next_node(copy_stack, stack_b) == 1)
			return (i);
		i++;
		copy_stack = copy_stack->next;
	}
	return (0);
}

int	compare_with_next_node(t_node *node, t_node *stack)
{
	int	min_number;
	int	max_number;

	min_number = get_min_number(stack);
	max_number = get_max_number(stack);
	if (node->next == (void *) 0)
		return (0);
	if (node->number != min_number)
	{
		if (node->number < node->next->number)
			return (1);
	}
	else
	{
		if (node->next->number != max_number)
			return (1);
	}
	return (0);
}

void	sort_stack_b(t_node **stack_b, t_node **stack_a, int not_sorted_point)
{
	int	i;

	i = 0;
	while (i < not_sorted_point)
	{
		command_rotate_up(stack_b, stack_a);
		ft_printf("rb\n");
		i++;
	}
	command_swap(*stack_b);
	ft_printf("sb\n");
	not_sorted_point = get_not_sorted_point(*stack_b);
	if (not_sorted_point > 0)
		sort_stack_b(stack_b, stack_a, not_sorted_point);
	i = 0;
	while (i < not_sorted_point)
	{
		command_rotate_down(stack_b, stack_a);
		ft_printf("rrb\n");
		i++;
	}
}
