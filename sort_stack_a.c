/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:47:19 by tayou             #+#    #+#             */
/*   Updated: 2023/03/24 23:16:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size_under_five(t_node **stack_a, t_node **stack_b, int divisor);
void	put_everynode_to_stack_a(t_node **stack_a, t_node **stack_b);
void	sort_size_over_five(t_node **stack_a, t_node **stack_b);

t_node	*sort_stack_a(t_node *stack_a, int divisor)
{
	t_node	*stack_b;
	int		stack_a_size;

	stack_b = (void *) 0;
	stack_a_size = get_stack_size(stack_a);
	if (stack_a_size <= 5)
		sort_size_under_five(&stack_a, &stack_b, divisor);
	else
		sort_size_over_five(&stack_a, &stack_b);
	free_list(stack_b);
	return (stack_a);
}

void	sort_size_under_five(t_node **stack_a, t_node **stack_b, int divisor)
{
	sort_until_sorted(stack_a, stack_b, divisor);
	check_min_number_is_top(stack_a, stack_b);
	check_max_number_is_top(stack_b, stack_a);
	if (check_perfectly_sorted_stack_b(*stack_b) == 1)
		put_everynode_to_stack_a(stack_a, stack_b);
}

void	put_everynode_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_b) != (void *) 0)
	{
		command_push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

void	sort_size_over_five(t_node **stack_a, t_node **stack_b)
{
	t_node	*stack_c;
	int		pivot;

	stack_c = (void *) 0;
	pivot = 0;
	rough_sort_to_stack_b(stack_a, stack_b, pivot);
	sort_size_under_five(stack_a, &stack_c, 30);
	/*
	ft_printf("-------------------stack_a--------------------\n");
	print_stack(*stack_a);
	ft_printf("-------------------stack_b--------------------\n");
	print_stack(*stack_b);
	*/
	push_max_to_stack_a(stack_a, stack_b);
}
