/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:10:55 by tayou             #+#    #+#             */
/*   Updated: 2023/03/17 12:00:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*initialize_stack_a(char **argv)
{
	t_node	*stack_a;
	t_node	*new_node;
	char	**string_array;
	int		i;

	string_array = get_string_array(argv);
	if (string_array == 0)
		exit(1);
	stack_a = get_new_node(ft_atoi(string_array[0]));
	i = 1;
	while (string_array[i] != (void *) 0)
	{
		new_node = get_new_node(ft_atoi(string_array[i]));
		if (new_node == 0)
		{
			free_array(string_array);
			exit(1);
		}
		stack_a = add_node_back(stack_a, new_node);
		i++;
	}
	free_array(string_array);
	return (stack_a);
}
