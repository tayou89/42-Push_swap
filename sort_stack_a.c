/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:47:19 by tayou             #+#    #+#             */
/*   Updated: 2023/03/27 00:39:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size_under_three(t_node **stack_a, t_node **stack_b);
void	sort_size_over_three(t_node **stack_a, t_node **stack_b);
void	check_stack_first_second(t_node **stack_a, t_node **stack_b);
void	quick_sort_stack_a(t_node **stack_a, t_node **stack_b, t_node *pivot);
void	push_over_pivot_node(t_node **stack_from, t_node **stack_to, int pivot);
void	push_top_to_stack_a(t_node **stack_from, t_node **stack_to);
void	make_it_sort(t_node **stack_a, t_node **stack_b);
static int	get_not_sorted_point(t_node *stack);

t_node	*sort_stack_a(t_node *stack_a)
{
	t_node	*stack_b;
	int		stack_a_size;

	stack_b = (void *) 0;
	stack_a_size = get_stack_size(stack_a);
	if (stack_a_size < 3)
		sort_size_under_three(&stack_a, &stack_b);
	else
		sort_size_over_three(&stack_a, &stack_b);
	free_list(stack_b);
	return (stack_a);
}

void	sort_size_under_three(t_node **stack_a, t_node **stack_b)
{
	int	 stack_b_size;

	stack_b_size = get_stack_size(*stack_b);
	if ((*stack_a)->number > (*stack_a)->next->number)
	{
		command_swap(*stack_a);
		if (stack_b_size >= 2 && (*stack_b)->number < (*stack_b)->next->number)
		{
			command_swap(*stack_b);
			ft_printf("ss\n");
		}
		else
			ft_printf("sa\n");
	}
}

void	sort_size_over_three(t_node **stack_a, t_node **stack_b)
{
	t_node	*pivot;

	pivot = get_new_node(0);
	if (pivot == (void *) 0)
	{
		free_list_both(*stack_a, *stack_b);
		exit(1);
	}
	rough_sort_to_stack_b(stack_a, stack_b, &pivot);
	sort_size_under_three(stack_a, stack_b);
	quick_sort_stack_a(stack_a, stack_b, pivot);
	if ((*stack_b) != (void *) 0)
	{
		command_push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	/*
//	push_max_to_stack_a(stack_a, stack_b);
	ft_printf("------------------stack_a------------------\n");
	print_stack(*stack_a);
	ft_printf("------------------stack_b------------------\n");
	print_stack(*stack_b);
	ft_printf("------------------pivot------------------\n");
	print_stack(pivot);
	if (check_perfectly_sorted_stack_a(*stack_a) == 1)
		ft_printf("perfectly_sorted!\n");
	else
		ft_printf("It's not sorted\n");
	*/
	free_list_both(pivot, *stack_b);
}

void	quick_sort_stack_a(t_node **stack_a, t_node **stack_b, t_node *pivot)
{
	t_node	*pivot_first;
	t_node	*pivot_last;
	int		stack_b_pivot;
	int		stack_a_max_number;
//	int		i;

	stack_a_max_number = get_max_number(*stack_a);
//	i = 0;
//	while (i < 9)
	while (pivot->next != (void *) 0)
	{
		if (pivot->number > stack_a_max_number - 2)
			pivot = pivot->next;
		pivot_first = pivot;
		pivot_last = pivot->next;
		/*
		if (pivot_first->number - pivot_last->number == 1)
		{
			command_push(stack_b, stack_a);
			ft_printf("pa\n");
		}
		else if (pivot_first->number - pivot_last->number == 2)
		{
			command_push(stack_b, stack_a);
			ft_printf("pa\n");
			command_push(stack_b, stack_a);
			ft_printf("pa\n");
			check_stack_first_second(stack_a, stack_b);
		}
		*/
//		else
//		{
		while (pivot_first->number != pivot_last->number)
		{
			stack_b_pivot = (pivot_first->number + pivot_last->number) / 2;
			while (pivot_first->number - stack_b_pivot > 3)
				stack_b_pivot = (pivot_first->number + stack_b_pivot) / 2;
//				ft_printf("stack_b_pivot: %d\n", stack_b_pivot);
			push_over_pivot_node(stack_b, stack_a, stack_b_pivot);
			check_stack_first_second(stack_a, stack_b);
			pivot_first->number = stack_b_pivot;
			if (check_perfectly_sorted_stack_a(*stack_a) != 1)
				make_it_sort(stack_a, stack_b);
			/*
			ft_printf("------------------stack_a------------------\n");
			print_stack(*stack_a);
			ft_printf("------------------stack_b------------------\n");
			print_stack(*stack_b);
			ft_printf("------------------pivot------------------\n");
			print_stack(pivot);
			if (check_perfectly_sorted_stack_a(*stack_a) == 1)
				ft_printf("Perfectly sorted!\n");
			else
				ft_printf("It's not sorted\n");
			*/
		}
//		}
//		i++;
		pivot = pivot->next;
	}
}

void	make_it_sort(t_node **stack_a, t_node **stack_b)
{
	int	not_sorted_point;
	int	i;

	not_sorted_point = get_not_sorted_point(*stack_a);
	i = 0;
	while (i < not_sorted_point)
	{
		command_rotate_up(stack_a, stack_b);
		command_rotate_up(stack_b, stack_a);
		ft_printf("rr\n");
		i++;
	}
	command_swap(*stack_a);
	ft_printf("sa\n");
	i = 0;
	while (i < not_sorted_point)
	{
		command_rotate_down(stack_a, stack_b);
		ft_printf("rra\n");
		i++;
	}
}

static int	get_not_sorted_point(t_node *stack)
{
	int	not_sorted_point;
	int	i;

	i = 0;
	while (stack->number < stack->next->number)
	{
		i++;
		stack = stack->next;
	}
	not_sorted_point = i;
	return (not_sorted_point);
}

void	check_stack_first_second(t_node **stack_a, t_node **stack_b)
{
	int	stack_b_size;

	stack_b_size = get_stack_size(*stack_b);
	if ((*stack_a)->number > (*stack_a)->next->number)
	{
		command_swap(*stack_a);
		/*
		if (stack_b_size >= 2 && (*stack_b)->number < (*stack_b)->next->number)
		{
			command_swap(*stack_b);
			ft_printf("ss\n");
		}
		else
		*/
			ft_printf("sa\n");
	}
	/*
	else if (stack_b_size >= 2 && (*stack_b)->number < (*stack_b)->next->number)
	{
		command_swap(*stack_b);
		ft_printf("sb\n");
	}
	*/
}

void	push_over_pivot_node(t_node **stack_from, t_node **stack_to, int pivot)
{
	t_node	*over_pivot_node;
	int		count;

	if ((*stack_from) == (void *) 0)
		return ;
	over_pivot_node = find_over_pivot_node(*stack_from, pivot);
	count = 0;
	while (over_pivot_node != (void *) 0)
	{
		rotate_over_pivot_to_top(stack_from, stack_to, pivot);
		push_top_to_stack_a(stack_from, stack_to);
		count++;
		if (count <= 2)
			check_stack_first_second(stack_to, stack_from);
		if ((*stack_from) == (void *) 0)
			over_pivot_node = (void *) 0;
		else
			over_pivot_node = find_over_pivot_node(*stack_from, pivot);
	}
}

void	push_top_to_stack_a(t_node **stack_from, t_node **stack_to)
{
	command_push(stack_from, stack_to);
	ft_printf("pa\n");
}

