/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:32:57 by tayou             #+#    #+#             */
/*   Updated: 2023/04/01 22:40:45 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_rotate_up(t_node **a, t_node **b, int top_right, int top_over);
void	a_rotate_up(t_node **a, t_node **b, int top_right, int bot_over);
void	both_rotate_down(t_node **a, t_node **b, int bot_right, int bot_over);
void	a_rotate_down(t_node **a, t_node **b, int bot_right, int top_over);

void	rotate_to_top(t_node **a, t_node **b, t_node *right, t_node *over)
{
	int	top_distance_right;
	int	bottom_distance_right;
	int	top_distance_over;
	int	bottom_distance_over;

	top_distance_right = get_distance_to_top(right);
	bottom_distance_right = get_distance_to_bottom(right);
	top_distance_over = get_distance_to_top(over);
	bottom_distance_over = get_distance_to_bottom(over);
	if (top_distance_right <= bottom_distance_right)
	{
		if ((top_distance_over - top_distance_right) < bottom_distance_over)
			both_rotate_up(a, b, top_distance_right, top_distance_over);
		else
			a_rotate_up(a, b, top_distance_right, bottom_distance_over);
	}
	else
	{
		if (bottom_distance_over - bottom_distance_right < top_distance_over)
			both_rotate_down(a, b, bottom_distance_right, bottom_distance_over);
		else
			a_rotate_down(a, b, bottom_distance_right, top_distance_over);
	}
}

void	both_rotate_up(t_node **a, t_node **b, int top_right, int top_over)
{
	int	i;

	i = 0;
	while (i < top_right && i < top_over)
	{
		command_rotate_up_both(a, b);
		ft_printf("rr\n");
		i++;
	}
	while (i < top_right)
	{
		command_rotate_up(a, b);
		ft_printf("ra\n");
		i++;
	}
	while (i < top_over)
	{
		command_rotate_up(b, a);
		ft_printf("rb\n");
		i++;
	}
}

void	a_rotate_up(t_node **a, t_node **b, int top_right, int bot_over)
{
	int	i;

	i = 0;
	while (i < top_right)
	{
		command_rotate_up(a, b);
		ft_printf("ra\n");
		i++;
	}
	i = 0;
	while (i < bot_over + 1)
	{
		command_rotate_down(b, a);
		ft_printf("rrb\n");
		i++;
	}
}

void	both_rotate_down(t_node **a, t_node **b, int bot_right, int bot_over)
{
	int	i;

	i = 0;
	while (i < bot_right + 1 && i < bot_over + 1)
	{
		command_rotate_down_both(a, b);
		ft_printf("rrr\n");
		i++;
	}
	while (i < bot_right + 1)
	{
		command_rotate_down(a, b);
		ft_printf("rra\n");
		i++;
	}
	while (i < bot_over + 1)
	{
		command_rotate_down(b, a);
		ft_printf("rrb\n");
		i++;
	}
}

void	a_rotate_down(t_node **a, t_node **b, int bot_right, int top_over)
{
	int	i;

	i = 0;
	while (i < bot_right + 1)
	{
		command_rotate_down(a, b);
		ft_printf("rra\n");
		i++;
	}
	i = 0;
	while (i < top_over)
	{
		command_rotate_up(b, a);
		ft_printf("rb\n");
		i++;
	}
}
