/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:03:36 by tayou             #+#    #+#             */
/*   Updated: 2023/04/05 12:34:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

void		check_exception(int argc, char **argv);
t_node		*get_stack_a(char **argv);
void		get_command_and_execute(t_node **stack_a, t_node **stack_b);
int			check_perfectly_sorted_stack_a(t_node *stack);

long long	ft_atoll(const char *str);
int			*get_int_array(char **string_array, int *int_count);
char		**get_string_array(char **argv);

void		command_swap(t_node *stack);
void		command_push(t_node **stack_from, t_node **stack_to);
void		command_rotate_up(t_node **stack_to_rotate, t_node **other_stack);
void		command_rotate_down(t_node **stack_to_rotate, t_node **other_stack);

void		command_swap_both(t_node *stack_a, t_node *stack_b);
void		command_rotate_up_both(t_node **stack_a, t_node **stack_b);
void		command_rotate_down_both(t_node **stack_a, t_node **stack_b);

t_node		*get_new_node(int number);
t_node		*add_node_back(t_node *stack, t_node *new_node);
t_node		*add_node_front(t_node *stack, t_node *new_node);
t_node		*del_node_front(t_node *stack);
t_node		*del_node_back(t_node *stack);
t_node		*find_last_node(t_node *stack);

int			ft_isspace(int c);
void		pass_space(char *str, int *i);
void		pass_notspace(char *str, int *i);
void		pass_sign(char *str, int *i);
char		*malloc_array(char **array, int i, int size);
int			get_stack_size(t_node *stack);
int			get_max_number(t_node *stack);
int			get_min_number(t_node *stack);

void		print_error_exit(t_node **stack_a, t_node **stack_b, char *command);

void		free_array(char **array);
void		free_list(t_node *list);
void		free_list_both(t_node *list_1, t_node *list_2);

#endif
