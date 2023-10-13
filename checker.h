/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:03:36 by tayou             #+#    #+#             */
/*   Updated: 2023/03/28 21:09:44 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "push_swap.h"

void	get_command_and_execute(t_node **stack_a, t_node **stack_b);

void	command_swap_both(t_node *stack_a, t_node *stack_b);
void	command_rotate_up_both(t_node **stack_a, t_node **stack_b);
void	command_rotate_down_both(t_node **stack_a, t_node **stack_b);

void	print_error_and_exit(t_node **stack_a, t_node **stack_b, char *command);

#endif
