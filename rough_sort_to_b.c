/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rough_sort_to_stack_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:06:39 by tayou             #+#    #+#             */
/*   Updated: 2023/03/27 23:39:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_stack_a_pivot(t_node *pivot, int pivot_number);
void	push_under_pivot(t_node **stack_a, t_node **stack_b, t_node *pivot);

void	rough_sort_to_b(t_node **stack_a, t_node **stack_b, t_node **pivot)
{
	int		stack_a_size;
	int		pivot_number;

	stack_a_size = get_stack_size(*stack_a);
	pivot_number = (*pivot)->number;
	if (stack_a_size < 3)
		return ;
	else if (stack_a_size <= 100)
		pivot_number = pivot_number + stack_a_size / 3;
	else if (stack_a_size <= 300)
		pivot_number = pivot_number + stack_a_size / 4;
	else
		pivot_number = pivot_number + stack_a_size / 5;
	*pivot = get_stack_a_pivot(*pivot, pivot_number);
	if (*pivot == (void *) 0)
	{
		free_list_both(*stack_a, *stack_b);
		return ;
	}
	push_under_pivot(stack_a, stack_b, *pivot);
	rough_sort_to_b(stack_a, stack_b, pivot);
}

t_node	*get_stack_a_pivot(t_node *pivot, int pivot_number)
{
	t_node	*new_node;

	new_node = get_new_node(pivot_number);
	if (new_node == (void *) 0)
	{
		free_list(pivot);
		return ((void *) 0);
	}
	pivot = add_node_front(pivot, new_node);
	return (pivot);
}

void	push_under_pivot(t_node **stack_a, t_node **stack_b, t_node *pivot)
{
	int	stack_b_size;
	int	middle_pivot;

	stack_b_size = get_stack_size(*stack_b);
	middle_pivot = (pivot->number + pivot->next->number) / 2;
	while (stack_b_size != pivot->number)
	{
		while ((*stack_a)->number >= pivot->number)
		{
			command_rotate_up(stack_a, stack_b);
			if (stack_b_size > 2 && (*stack_b)->number < middle_pivot)
			{
				command_rotate_up(stack_b, stack_a);
				ft_printf("rr\n");
			}
			else
				ft_printf("ra\n");
		}
		command_push(stack_a, stack_b);
		ft_printf("pb\n");
		stack_b_size = get_stack_size(*stack_b);
	}
}
