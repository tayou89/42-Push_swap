/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/16 14:57:33 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deque	*get_deque(t_node *stack)
{
	t_deque	*first_last;

	first_last = (t_deque *) malloc(sizeof(t_deque));
	first_last->first = stack;
	while (stack->next != (void *) 0)
		stack = stack->next;
	first_last->last = stack;
	return (first_last);
}

int	check_perfectly_sorted_stack_a(t_node *stack)
{
	int		min_number;
	int		max_number;
	t_node	*stack_head;

	stack_head = stack;
	min_number = get_min_number(stack);
	max_number = get_max_number(stack);
	while (stack->next != (void *) 0)
	{
		if (stack->number == max_number && stack->next->number != min_number)
			return (0);
		if (stack->number != max_number && 
			stack->next->number != stack->number + 1)
			return (0);
		stack = stack->next;
	}
	if (stack->number == max_number && stack_head->number != min_number)
		return (0);
	if (stack->number != max_number && stack_head->number != stack->number + 1)
		return (0);
	return (1);
}

int	check_perfectly_sorted_stack_b(t_node *stack)
{
	int 	min_number;
	int		max_number;
	t_node	*stack_head;

	if (stack == (void *) 0)
		return (1);
	stack_head = stack;
	min_number = get_min_number(stack);
	max_number = get_max_number(stack);
	while (stack->next != (void *) 0)
	{
		if (stack->number == min_number && stack->next->number != max_number)
			return (0);
		if (stack->number != min_number && 
			stack->next->number != stack->number - 1)
			return (0);
		stack = stack->next;
	}
	if (stack->number == min_number && stack_head->number != max_number)
		return (0);
	if (stack->number != min_number && stack_head->number != stack->number - 1)
		return (0);
	return (1);
}

void	check_both_stack(t_node *stack_a, t_node *stack_b)
{
	if (stack_a->number > stack_a->next->number &&
		stack_b->number < stack_b->next->number)
	{
		command_swap(stack_a);
		command_swap(stack_b);
		ft_printf("ss\n");
		return ;
	}
	if (stack_a->number > stack_a->next->number &&
		stack_b->number > stack_b->next->number)
	{
		command_swap(stack_a);
		ft_printf("sa\n");
		return ;
	}
	if (stack_a->number < stack_a->next->number &&
		stack_b->number < stack_b->next->number)
	{
		command_swap(stack_b);
		ft_printf("sb\n");
		return ;
	}
	else
		return ;
}

void	check_stack_a(t_node *stack_a)
{
	if (stack_a->number > stack_a->next->number)
	{
		command_swap(stack_a);
		ft_printf("sa\n");
	}
	return ;
}

void	check_stack_b(t_node *stack_b)
{
	if (stack_b->number < stack_b->next->number)
	{
		command_swap(stack_b);
		ft_printf("sb\n");
	}
}

void	check_first_second(t_node *stack_a, t_node *stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = get_stack_size(stack_a);
	stack_b_size = get_stack_size(stack_b);
	if (stack_a_size >= 2 && stack_b_size >= 2)
	{
		check_both_stack(stack_a, stack_b);
		return ;
	}
	if (stack_a_size >= 2 && stack_b_size < 2)
	{
		check_stack_a(stack_a);
		return ;
	}
	if (stack_a_size < 2 && stack_b_size >= 2)
	{
		check_stack_b(stack_b);
		return ;
	}
}

void	check_first_last(t_node *stack_a, t_node *stack_b)
{
	t_node	*last_node;

	last_node = find_node_last(stack_a);
	if (last_node->number > stack_a->number)
	{
		command_push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

int	check_if_sorted_stack_b(t_node *stack_b)
{
	t_node	*stack_head;
	int		min_number;
	int		max_number;
	int		i;

	stack_head = stack_b;
	min_number = get_min_number(stack_b);
	max_number = get_max_number(stack_b);
	i = 0;
	while (stack_b->next != (void *) 0)
	{
		if (stack_b->number != min_number &&
			stack_b->number < stack_b->next->number)
			return (i);
		if (stack_b->number == min_number &&
			stack_b->next->number != max_number)
			return (i);
		i++;
		stack_b = stack_b->next;
	}
	if (stack_b->number != min_number && stack_head->number > stack_b->number)
		return (i);
	if (stack_b->number == min_number && stack_head->number != max_number)
		return (i);
	return (0);
}

t_node	*sort_stack_b(t_node *stack_b, int not_sorted_point)
{
	int	i;

	i = 0;
	while (i < not_sorted_point)
	{
		command_rotate_up(stack_b);
		ft_printf("rb\n");
		i++;
	}
	command_swap(stack_b);
	ft_printf("sb\n");
	i = 0;
	while (i < not_sorted_point)
	{
		command_rotate_down(stack_b);
		ft_printf("rrb\n");
		i++;
	}
	return (stack_b);
}

t_node	*sort_stack_a(t_node *stack_a)
{
	t_node	*stack_b;
	int		stack_b_size;
	int		not_sorted_point;
	int		i;
	t_node	*copy_stack_b;
	t_node	*copy_stack_a;

	stack_b = (void *) 0;
	if (check_perfectly_sorted_stack_a(stack_a) == 1)
		return (stack_a);
	while (check_perfectly_sorted_stack_a(stack_a) != 1 ||
		   check_perfectly_sorted_stack_b(stack_b) != 1)
	{
		i = 0;
		copy_stack_b = stack_b;
		if (copy_stack_b == (void *) 0)
			ft_printf("stack_b[0]: NULL\n");
		while (copy_stack_b != (void *) 0)
		{
			ft_printf("stack_b[%d]: %d\n", i, copy_stack_b->number);
			copy_stack_b = copy_stack_b->next;
			i++;
		}
		i = 0;
		copy_stack_a = stack_a;
		if (copy_stack_a == (void *) 0)
			ft_printf("stack_a[0]: NULL\n");
		while (copy_stack_a != (void *) 0)
		{
			ft_printf("stack_a[%d]: %d\n", i, copy_stack_a->number);
			copy_stack_a = copy_stack_a->next;
			i++;
		}
		check_first_second(stack_a, stack_b); 
		check_first_last(stack_a, stack_b);
		stack_b_size = get_stack_size(stack_b);
		if (stack_b_size < 2)
			continue ;
		not_sorted_point = check_if_sorted_stack_b(stack_b);
		if (not_sorted_point > 0)
			sort_stack_b(stack_b, not_sorted_point);
	}
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*copy_stack;
	int		i;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	copy_stack = stack_a;
	i = 0;
	while (copy_stack != (void *) 0)
	{
		ft_printf("stack_a[%d]->number: %d\n", i, copy_stack->number);
		i++;
		copy_stack = copy_stack->next;
	}
	stack_a = sort_stack_a(stack_a);
	copy_stack = stack_a;
	i = 0;
	while (copy_stack != (void *) 0)
	{
		ft_printf("stack_a[%d]->number: %d\n", i, copy_stack->number);
		i++;
		copy_stack = copy_stack->next;
	}
	free_list(stack_a);
	system("leaks push_swap");
	return (0);
}
