/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/21 05:04:49 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*sort_stack_a(t_node *stack_a);

int	main(int argc, char *argv[])
{
	t_node	*stack_a;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	stack_a = sort_stack_a(stack_a);
	free_list(stack_a);
	return (0);
}

t_node	*sort_stack_a(t_node *stack_a)
{
	t_node	*stack_b;

	stack_b = (void *) 0;
	sort_until_sorted(&stack_a, &stack_b);
	check_min_number_is_top(&stack_a, &stack_b);
	check_max_number_is_top(&stack_b, &stack_a);
	put_everynode_to_stack_a(&stack_a, &stack_b);
	free_list(stack_b);
	return (stack_a);
}
