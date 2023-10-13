/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/26 18:46:42 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	stack_a = sort_stack_a(stack_a);
	free_list(stack_a);
	return (0);
}
/*
void	push_other_node(t_node **stack_a, t_node **stack_b)
{
	while (*stack_a != (void *) 0)
	{
		command_push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	roughly_sort_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*pivot;
	t_node	*pivot_head;
	t_node	*last_pivot;
	int		pivot_number;
	int		stack_a_size;
	int		rb_count;
	int		i;

	pivot = get_pivot(*stack_b, 25);
	pivot_head = pivot;
	last_pivot = find_last_node(pivot);
	last_pivot = last_pivot->prev;
	rb_count = 0;
	while (*stack_b != (void *) 0)
	{
		if (last_pivot == (void *) 0)
			pivot_number = 0;
		else
			pivot_number = last_pivot->number;
		while ((*stack_b)->number < pivot_number)
		{
			command_rotate_up(stack_b, stack_a);
			ft_printf("rb\n");
			rb_count++;
		}
		command_push(stack_b, stack_a);
		ft_printf("pa\n");
		stack_a_size = get_stack_size(*stack_a);
		if (stack_a_size == pivot->number)
		{
			if (pivot->next != (void *) 0)
			{
				i = 0;
				while (i < rb_count)
				{
					command_rotate_down(stack_b, stack_a);
					ft_printf("rrb\n");
					i++;
				}
				last_pivot = last_pivot->prev;
				pivot = pivot->next;
			}
		}
	}
	free_list(pivot_head);
}
*/
