/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_until_sorted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:00:35 by tayou             #+#    #+#             */
/*   Updated: 2023/03/21 07:18:49 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_until_sorted(t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	if (check_perfectly_sorted_stack_a(*stack_a) == 1)
		return ;
//	while (check_perfectly_sorted_stack_a(*stack_a) == 0 ||
//		   check_perfectly_sorted_stack_b(*stack_b) == 0)
	while (i < 5)
	{
		check_first_second_node(stack_a, stack_b);
		ft_printf("-------------check_first_second_node-------------\n");
		ft_printf("--------------------stack_a-------------------\n");
		print_stack(*stack_a);
		ft_printf("--------------------stack_b-------------------\n");
		print_stack(*stack_b);
		check_first_last_node(stack_a, stack_b);
		ft_printf("-------------check_first_last_node-------------\n");
		ft_printf("--------------------stack_a-------------------\n");
		print_stack(*stack_a);
		ft_printf("--------------------stack_b-------------------\n");
		print_stack(*stack_b);
		i++;
	}
	ft_printf("--------------------after while-------------------\n");
	ft_printf("--------------------stack_a-------------------\n");
	print_stack(*stack_a);
	ft_printf("--------------------stack_b-------------------\n");
	print_stack(*stack_b);
	check_max_number_is_top(stack_b, stack_a);
}
