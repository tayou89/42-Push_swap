/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_and_execute.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:52:12 by tayou             #+#    #+#             */
/*   Updated: 2023/03/29 11:47:09 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	execute_command(t_node **stack_a, t_node **stack_b, char *command);
void	execute_command_s(t_node **stack_a, t_node **stack_b, char *command);
void	execute_command_p(t_node **stack_a, t_node **stack_b, char *command);
void	execute_command_r(t_node **stack_a, t_node **stack_b, char *command);

void	get_command_and_execute(t_node **stack_a, t_node **stack_b)
{
	char	*command;

	command = get_next_line(0);
	if (command == (void *) 0)
		return ;
	while (*command != '\0')
	{
		execute_command(stack_a, stack_b, command);
		free(command);
		command = get_next_line(0);
	}
	free(command);
}

void	execute_command(t_node **stack_a, t_node **stack_b, char *command)
{
	if (ft_strncmp(command, "s", 1) == 0)
		execute_command_s(stack_a, stack_b, command);
	else if (ft_strncmp(command, "p", 1) == 0)
		execute_command_p(stack_a, stack_b, command);
	else if (ft_strncmp(command, "r", 1) == 0)
		execute_command_r(stack_a, stack_b, command);
	else
		print_error_and_exit(stack_a, stack_b, command);
}

void	execute_command_s(t_node **stack_a, t_node **stack_b, char *command)
{
	int	check_size;

	check_size = 2;
	if (ft_strncmp(command, "sa", check_size) == 0)
		command_swap(*stack_a);
	else if (ft_strncmp(command, "sb", check_size) == 0)
		command_swap(*stack_b);
	else if (ft_strncmp(command, "ss", check_size) == 0)
		command_swap_both(*stack_a, *stack_b);
	else
		print_error_and_exit(stack_a, stack_b, command);
}

void	execute_command_p(t_node **stack_a, t_node **stack_b, char *command)
{
	int	check_size;

	check_size = 2;
	if (ft_strncmp(command, "pa", check_size) == 0)
		command_push(stack_b, stack_a);
	else if (ft_strncmp(command, "pb", check_size) == 0)
		command_push(stack_a, stack_b);
	else
		print_error_and_exit(stack_a, stack_b, command);
}

void	execute_command_r(t_node **stack_a, t_node **stack_b, char *command)
{
	int	check_size;

	check_size = 3;
	if (ft_strncmp(command, "ra\n", check_size) == 0)
		command_rotate_up(stack_a, stack_b);
	else if (ft_strncmp(command, "rb\n", check_size) == 0)
		command_rotate_up(stack_b, stack_a);
	else if (ft_strncmp(command, "rr\n", check_size) == 0)
		command_rotate_up_both(stack_a, stack_b);
	else if (ft_strncmp(command, "rra", check_size) == 0)
		command_rotate_down(stack_a, stack_b);
	else if (ft_strncmp(command, "rrb", check_size) == 0)
		command_rotate_down(stack_b, stack_a);
	else if (ft_strncmp(command, "rrr", check_size) == 0)
		command_rotate_down_both(stack_a, stack_b);
	else
		print_error_and_exit(stack_a, stack_b, command);
}
