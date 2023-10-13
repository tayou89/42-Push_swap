/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:21:43 by tayou             #+#    #+#             */
/*   Updated: 2023/03/28 20:57:24 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int number)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (new_node == 0)
		return (0);
	new_node->number = number;
	new_node->changed = 0;
	new_node->prev = (void *) 0;
	new_node->next = (void *) 0;
	return (new_node);
}

t_node	*add_node_back(t_node *stack, t_node *new_node)
{
	t_node	*copy_head;

	if (stack == (void *) 0)
	{
		stack = new_node;
		return (stack);
	}
	copy_head = stack;
	while (copy_head->next != (void *) 0)
		copy_head = copy_head->next;
	copy_head->next = new_node;
	new_node->prev = copy_head;
	return (stack);
}

t_node	*add_node_front(t_node *stack, t_node *new_node)
{
	if (new_node == (void *) 0)
		return (stack);
	if (stack == (void *) 0)
	{
		stack = new_node;
		return (stack);
	}
	new_node->next = stack;
	stack->prev = new_node;
	stack = new_node;
	return (stack);
}

t_node	*del_node_front(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	if (stack->next != (void *) 0)
		stack->next->prev = (void *) 0;
	stack = stack->next;
	free(temp);
	return (stack);
}

t_node	*del_node_back(t_node *stack)
{
	t_node	*copy_stack;

	copy_stack = stack;
	while (copy_stack->next != (void *) 0)
		copy_stack = copy_stack->next;
	free(copy_stack);
	return (stack);
}
