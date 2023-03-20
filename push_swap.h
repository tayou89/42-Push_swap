/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:39:01 by tayou             #+#    #+#             */
/*   Updated: 2023/03/20 13:40:53 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				number;
	int				changed;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	t_node	*first;
	t_node	*last;
}	t_deque;


void		check_exception(int argc, char **argv);

t_node		*initialize_stack_a(char **argv);

void		command_swap(t_node *stack);
void		command_push(t_node **stack_from, t_node **stack_to);
void		command_rotate_up(t_node **stack_to_rotate, t_node **other_stack);
void		command_rotate_down(t_node **stack_to_rotate, t_node **other_stack);

t_node		*find_last_node(t_node *stack);
t_node		*get_new_node(int number);
t_node		*add_node_back(t_node *stack, t_node *new_node);
t_node		*add_node_front(t_node *stack, t_node *new_node);
t_node		*del_node_front(t_node *stack);

char		**get_string_array(char **argv);
int			*get_int_array(char **string_array, int *int_count);
t_node		*get_stack_a(char **argv);
long long	ft_atoll(const char *str);

void		sort_until_sorted(t_node **stack_a, t_node **stack_b);

int			check_perfectly_sorted_stack_a(t_node *stack);
int			check_perfectly_sorted_stack_b(t_node *stack);
void		check_first_second_node(t_node **stack_a, t_node **stack_b);
void		check_if_sorted_stack_b(t_node **stack_b, t_node **stack_a);
void		check_first_last_node(t_node **stack_a, t_node **stack_b);
void		check_max_number_is_top(t_node **stack_b, t_node **stack_a);
void		check_min_number_is_top(t_node **stack_a, t_node **stack_b);

void		put_everynode_to_stack_a(t_node **stack_a, t_node **stack_b);

int			ft_isspace(int c);
void		pass_space(char *str, int *i);
int			get_stack_size(t_node *stack);
int			get_max_number(t_node *stack);
int			get_min_number(t_node *stack);

int			get_max_number_index(t_node *stack);
int			get_min_number_index(t_node *stack);

void		free_array(char **array);
void		free_list(t_node *list);
void		free_list_both(t_node *list_1, t_node *list_2);

void		print_stack(t_node *stack);

#endif
