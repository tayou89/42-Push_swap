/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:39:01 by tayou             #+#    #+#             */
/*   Updated: 2023/03/16 15:08:20 by tayou            ###   ########.fr       */
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
void		command_push(t_node *stack_from, t_node *stack_to);
void		command_rotate_up(t_node *stack);
void		command_rotate_down(t_node *stack);

t_node		*find_node_last(t_node *stack);
t_node		*get_new_node(int number);
t_node		*add_node_back(t_node **stack, t_node *new_node);
t_node		*add_node_front(t_node *stack, t_node *new_node);
t_node		*del_node_front(t_node *stack);

char		**get_string_array(char **argv);
int			*get_int_array(char **string_array, int *int_count);
t_node		*get_stack_a(char **argv);
long long	ft_atoll(const char *str);

int			ft_isspace(int c);
void		pass_space(char *str, int *i);
int			get_stack_size(t_node *stack);
int			get_max_number(t_node *stack);
int			get_min_number(t_node *stack);

void		free_array(char **array);
void		free_list(t_node *list);

#endif
