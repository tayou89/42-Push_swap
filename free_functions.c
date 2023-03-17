/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funtions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:54:21 by tayou             #+#    #+#             */
/*   Updated: 2023/03/17 12:51:07 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != (void *) 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_list(t_node *list)
{
	t_node	*list_head;

	if (list == (void *) 0)
		return ;
	while (list != (void *) 0)
	{
		list_head = list;
		list = list->next;
		free(list_head);
	}
	list = (void *) 0;
}

void	free_list_both(t_node *list_1, t_node *list_2)
{
	free_list(list_1);
	free_list(list_2);
	exit(1);
}
