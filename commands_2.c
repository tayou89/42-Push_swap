/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:14:02 by tayou             #+#    #+#             */
/*   Updated: 2023/03/26 22:15:25 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_up_by_distance(t_node **to_rotate, t_node **other, int distance)
{
	t_node	*check_node;
	int	max_number_to_rotate;
	int	max_number_other;
	int	i;

	max_number_to_rotate = get_max_number(*to_rotate);
	max_number_other = get_max_number(*other);
	i = 0;
	while (i < distance)
	{
		command_rotate_up(to_rotate, other);
		if (max_number_to_rotate > max_number_other) 
		{
			if ((*other) != (void *) 0 && (*other)->number != max_number_other)
			{
				check_node = find_max_node(*other);
				if (get_distance_to_top(check_node) <= get_distance_to_bottom(check_node))
				{
					command_rotate_up(other, to_rotate);
					ft_printf("rr\n");
				}
				else
					ft_printf("ra\n");
			}
			else
				ft_printf("ra\n");
		}
		else
			ft_printf("rb\n");
		i++;
	}
}

void	rotate_down_by_distance(t_node **to_rotate, t_node **other, int distance)
{
	t_node	*check_node;
	int	max_number_to_rotate;
	int	max_number_other;
	int	i;

	max_number_to_rotate = get_max_number(*to_rotate);
	max_number_other = get_max_number(*other);
	i = 0;
	while (i < distance)
	{
		command_rotate_down(to_rotate, other);
		if (max_number_to_rotate > max_number_other) 
		{
			if ((*other) != (void *) 0 && (*other)->number != max_number_other)
			{
				check_node = find_max_node(*other);
				if (get_distance_to_top(check_node) > get_distance_to_bottom(check_node))
				{
					command_rotate_down(other, to_rotate);
					ft_printf("rrr\n");
				}
				else
					ft_printf("rra\n");
			}
			else
				ft_printf("rra\n");
		}
		else
			ft_printf("rrb\n");
		i++;
	}
}
