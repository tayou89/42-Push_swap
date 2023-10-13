/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:47:19 by tayou             #+#    #+#             */
/*   Updated: 2023/03/27 21:58:07 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sort_stack_a(t_node *stack_a)
{
	t_node	*stack_b;
	int		stack_a_size;

	stack_b = (void *) 0;
	stack_a_size = get_stack_size(stack_a);
	if (stack_a_size < 30)
		sort_under_thirty(&stack_a, &stack_b);
	else
		sort_over_thirty(&stack_a, &stack_b);
	free_list(stack_b);
	return (stack_a);
}
