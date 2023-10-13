/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:00:44 by tayou             #+#    #+#             */
/*   Updated: 2023/04/05 12:13:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	command_swap(t_node *stack)
{
	int	temp;
	int	size;

	size = get_stack_size(stack);
	if (size == 1 || stack == (void *) 0)
		return ;
	temp = stack->number;
	stack->number = stack->next->number;
	stack->next->number = temp;
}

void	command_push(t_node **stack_from, t_node **stack_to)
{
	t_node	*new_node;

	if (*stack_from == (void *) 0)
		return ;
	new_node = get_new_node((*stack_from)->number);
	if (new_node == (void *) 0)
		free_list_both(*stack_from, *stack_to);
	*stack_to = add_node_front(*stack_to, new_node);
	*stack_from = del_node_front(*stack_from);
}

void	command_rotate_up(t_node **stack_to_rotate, t_node **other_stack)
{
	int		size;
	t_node	*new_node;

	size = get_stack_size(*stack_to_rotate);
	if (size == 1 || *stack_to_rotate == (void *) 0)
		return ;
	new_node = get_new_node((*stack_to_rotate)->number);
	if (new_node == (void *) 0)
		free_list_both(*stack_to_rotate, *other_stack);
	*stack_to_rotate = add_node_back(*stack_to_rotate, new_node);
	*stack_to_rotate = del_node_front(*stack_to_rotate);
}

void	command_rotate_down(t_node **stack_to_rotate, t_node **other_stack)
{
	t_node	*new_node;
	t_node	*last_node;
	int		size;

	size = get_stack_size(*stack_to_rotate);
	if (size == 1 || *stack_to_rotate == (void *) 0)
		return ;
	last_node = find_last_node(*stack_to_rotate);
	new_node = get_new_node(last_node->number);
	if (new_node == (void *) 0)
		free_list_both(*stack_to_rotate, *other_stack);
	*stack_to_rotate = add_node_front(*stack_to_rotate, new_node);
	last_node->prev->next = (void *) 0;
	free(last_node);
	last_node = (void *) 0;
}
