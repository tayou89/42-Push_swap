/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:21:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/20 06:40:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack)
{
	int	i;

	i = 0;
	while (stack != (void *) 0)
	{
		ft_printf("stack[%d]: %d\n", i, stack->number);
		i++;
		stack = stack->next;
	}
}

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

int	check_stack_a(t_node **stack_a, t_node **stack_b)
{
	int	max_number;
	int	min_number;

	max_number = get_max_number(*stack_a);
	min_number = get_min_number(*stack_a);
	if ((*stack_a)->number == max_number &&
		(*stack_a)->next->number == min_number)
	{
		command_rotate_up(stack_a, stack_b);
		ft_printf("ra\n");
	}
	if ((*stack_a)->number > (*stack_a)->next->number)
		return (1);
	return (0);
}

int	check_stack_b(t_node **stack_b, t_node **stack_a)
{
	int	max_number;
	int	min_number;

	max_number = get_max_number(*stack_b);
	min_number = get_min_number(*stack_b);
	if ((*stack_b)->number == min_number &&
		(*stack_b)->next->number == max_number)
	{
		command_rotate_up(stack_b, stack_a);
		ft_printf("rb\n");
	}
	if ((*stack_b)->number < (*stack_b)->next->number)
		return (1);
	return (0);
}

void	check_both_stack(t_node **stack_a, t_node **stack_b)
{
	if (check_stack_a(stack_a, stack_b) == 1 &&
		check_stack_b(stack_b, stack_a) == 1)
	{
		command_swap(*stack_a);
		command_swap(*stack_b);
		ft_printf("ss\n");
	}
	if (check_stack_a(stack_a, stack_b) == 1 &&
		check_stack_b(stack_b, stack_a) != 1)
	{
		command_swap(*stack_a);
		ft_printf("sa\n");
	}
	if (check_stack_a(stack_a, stack_b) != 1 &&
		check_stack_b(stack_b, stack_a) == 1)
	{
		command_swap(*stack_b);
		ft_printf("sb\n");
	}
}

void	check_first_second(t_node **stack_a, t_node **stack_b)
{
	int	stack_a_size;
	int	stack_b_size;

	stack_a_size = get_stack_size(*stack_a);
	stack_b_size = get_stack_size(*stack_b);
	if (stack_a_size >= 2 && stack_b_size >= 2)
		check_both_stack(stack_a, stack_b);
	else if (stack_a_size >= 2 && stack_b_size < 2)
	{
		if (check_stack_a(stack_a, stack_b) == 1)
		{
			command_swap(*stack_a);
			ft_printf("sa\n");
		}
	}
	else if (stack_a_size < 2 && stack_b_size >= 2)
	{
		if (check_stack_b(stack_b, stack_a) == 1)
		{
			command_swap(*stack_b);
			ft_printf("sb\n");
		}
	}
}

void	check_first_last(t_node **stack_a, t_node **stack_b)
{
	t_node	*last_node;

	last_node = find_last_node(*stack_a);
	if (last_node->number > (*stack_a)->number)
	{
		command_push(stack_a, stack_b);
		ft_printf("pb\n");
	}
	else
	{
		command_rotate_down(stack_a, stack_b);
		ft_printf("rra\n");
		check_first_last(stack_a, stack_b);
	}
}

int	compare_with_next_node(t_node *node, t_node *stack)
{
	int	min_number;
	int	max_number;

	min_number = get_min_number(stack);
	max_number = get_max_number(stack);
	if (node->next == (void *) 0)
		return (0);
	if (node->number != min_number)
	{
		if (node->number < node->next->number)
			return (1);
	}
	else
	{
		if (node->next->number != max_number)
			return (1);
	}
	return (0);
}

int	get_not_sorted_point(t_node *stack_b)
{
	t_node	*copy_stack;
	int		i;

	copy_stack = stack_b;
	i = 0;
	while (copy_stack != (void *) 0)
	{
		if (compare_with_next_node(copy_stack, stack_b) == 1)
			return (i);
		i++;
		copy_stack = copy_stack->next;
	}
	return (0);
}
	
void	sort_stack_b(t_node **stack_b, t_node **stack_a, int not_sorted_point)
{
	int	i;

	i = 0;
	while (i < not_sorted_point)
	{
		command_rotate_up(stack_b, stack_a);
		ft_printf("rb\n");
		i++;
	}
	command_swap(*stack_b);
	ft_printf("sb\n");
	not_sorted_point = get_not_sorted_point(*stack_b);
	if (not_sorted_point > 0)
		sort_stack_b(stack_b, stack_a, not_sorted_point);
	i = 0;
	while (i < not_sorted_point)
	{
		command_rotate_down(stack_b, stack_a);
		ft_printf("rrb\n");
		i++;
	}
}

void	check_if_sorted_stack_b(t_node **stack_b, t_node **stack_a)
{
	int		size;
	int		not_sorted_point;

	size = get_stack_size(*stack_b);
	if (size < 3)
		return ;
	not_sorted_point = get_not_sorted_point(*stack_b);
	if (not_sorted_point > 0)
		sort_stack_b(stack_b, stack_a, not_sorted_point);
}

int	get_max_number_index(t_node *stack, int max_number)
{
	int	i;
	int	max_number_index;

	i = 0;
	while (stack->number != max_number)
	{
		stack = stack->next;
		i++;
	}
	max_number_index = i;
	return (max_number_index);
}

void	put_max_on_top(t_node **stack_to_rotate, t_node **other_stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		command_rotate_up(stack_to_rotate, other_stack);
		ft_printf("rb\n");
		i++;
	}
}

void	check_max_number_is_top(t_node **stack_to_check, t_node **other_stack)
{
	int	stack_size;
	int	max_number;
	int	max_number_index;

	stack_size = get_stack_size(*stack_to_check);
	if (stack_size < 2)
		return ;
	max_number = get_max_number(*stack_to_check);
	max_number_index = get_max_number_index(*stack_to_check, max_number);
	if (max_number_index > 0)
		put_max_on_top(stack_to_check, other_stack, max_number_index);
}

void	sort_until_sorted(t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (check_perfectly_sorted_stack_a(*stack_a) == 0 ||
		   check_perfectly_sorted_stack_b(*stack_b) == 0)
	{
		check_first_second(stack_a, stack_b);
		check_if_sorted_stack_b(stack_b, stack_a);
		check_max_number_is_top(stack_b, stack_a);
		check_first_last(stack_a, stack_b);
		i++;
	}
}

int	get_min_number_index(t_node *stack)
{
	int	min_number;
	int	min_number_index;
	int	i;

	min_number = get_min_number(stack);
	i = 0;
	while (stack->number != min_number)
	{
		stack = stack->next;
		i++;
	}
	min_number_index = i;
	return (min_number_index);
}

void	put_min_on_top(t_node **stack_a, t_node **stack_b, int index, int point)
{
	int	min_number;

	min_number = get_min_number(*stack_a);
	if (index > point)
	{
		while ((*stack_a)->number != min_number)
		{
			command_rotate_down(stack_a, stack_b);
			ft_printf("rra\n");
		}
	}
	else
	{
		while ((*stack_a)->number != min_number)
		{
			command_rotate_up(stack_a, stack_b);
			ft_printf("ra\n");
		}
	}
}

void	check_min_number_is_top(t_node **stack_a, t_node **stack_b)
{
	int	stack_size;
	int	middle_point;
	int	min_number_index;

	stack_size = get_stack_size(*stack_a);
	if (stack_size < 2)
		return ;
	middle_point = stack_size / 2;
	min_number_index = get_min_number_index(*stack_a);
	put_min_on_top(stack_a, stack_b, min_number_index, middle_point);
}

void	put_everynode_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	while ((*stack_b) != (void *) 0)
	{
		command_push(stack_b, stack_a);
		ft_printf("pa\n");
	}
}

t_node	*sort_stack_a(t_node *stack_a)
{
	t_node	*stack_b;

	stack_b = (void *) 0;
	if (check_perfectly_sorted_stack_a(stack_a) == 1)
		return (stack_a);
	sort_until_sorted(&stack_a, &stack_b);
	check_min_number_is_top(&stack_a, &stack_b);
	put_everynode_to_stack_a(&stack_a, &stack_b);
	free_list(stack_b);
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;

	check_exception(argc, argv);
	stack_a = get_stack_a(argv);
	stack_a = sort_stack_a(stack_a);
	free_list(stack_a);
	return (0);
}
