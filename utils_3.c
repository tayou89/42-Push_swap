/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:17:03 by tayou             #+#    #+#             */
/*   Updated: 2023/03/28 15:20:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance_to_top(t_node *node)
{
	int	distance;
	int	i;

	i = 0;
	while (node->prev != (void *) 0)
	{
		node = node->prev;
		i++;
	}
	distance = i;
	return (distance);
}

int	get_distance_to_bottom(t_node *node)
{
	int	distance;
	int	i;

	i = 0;
	while (node->next != (void *) 0)
	{
		node = node->next;
		i++;
	}
	distance = i;
	return (distance);
}
