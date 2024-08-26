/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:00:18 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 17:11:17 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int		check_a_is_sorted(t_node *stack_a);
int		check_top_is_min_number(t_node *stack_a);

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	stack_b = (void *) 0;
	get_command_and_execute(&stack_a, &stack_b);
	if (check_a_is_sorted(stack_a) != 1 || stack_b != (void *) 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_list_both(stack_a, stack_b);
	return (0);
}

int	check_a_is_sorted(t_node *stack_a)
{
	if (stack_a == (void *) 0)
		return (0);
	if (check_top_is_min_number(stack_a) != 1)
		return (0);
	if (check_perfectly_sorted_stack_a(stack_a) != 1)
		return (0);
	return (1);
}

int	check_top_is_min_number(t_node *stack_a)
{
	int	min_number;

	min_number = get_min_number(stack_a);
	if (stack_a->number != min_number)
		return (0);
	else
		return (1);
}
