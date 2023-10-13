/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:38:26 by tayou             #+#    #+#             */
/*   Updated: 2023/03/24 23:24:51 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*fill_pivot(int divisor, int pivot_count);

t_node	*get_pivot(t_node *stack, int	divisor)
{
	t_node	*pivot;
	int		pivot_count;
	int		stack_size;

	stack_size = get_stack_size(stack);
	pivot_count = stack_size / divisor;
	if (pivot_count == 0)
		return ((void *) 0);
	pivot = fill_pivot(divisor, pivot_count);
	if (pivot == (void *) 0)
	{
		free_list(stack);
		exit(1);
	}
	return (pivot);
}

t_node	*fill_pivot(int divisor, int pivot_count)
{
	t_node	*pivot;
	t_node	*new_node;
	int		i;
	int		j;

	pivot = (void *) 0;
	i = 0;
	while (i < pivot_count)
	{
		j = i + 1;
		new_node = get_new_node(divisor * j);
		if (new_node == (void *) 0)
		{
			free_list(pivot);
			return ((void *) 0);
		}
		if (pivot == (void *) 0)
			pivot = new_node;
		else
			pivot = add_node_back(pivot, new_node);
		i++;
	}
	return (pivot);
}

