/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:51:37 by tayou             #+#    #+#             */
/*   Updated: 2023/04/07 10:36:50 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_number(char **str);
static int	check_if_int(char **str);
static int	check_if_duplicate(char **str);
static int	check_int_by_over_flow(char *str);

void	check_exception(int argc, char **argv)
{
	char	**str;

	if (argc <= 1)
		exit(1);
	str = get_string_array(argv);
	if (check_if_number(str) == 0 || check_if_int(str) == 0
		|| check_if_duplicate(str) == 0)
	{
		ft_printf("Error\n");
		free_array(str);
		exit(2);
	}
	free_array(str);
}

static int	check_if_number(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != (void *) 0)
	{
		j = 0;
		pass_space(str[i], &j);
		pass_sign(str[i], &j);
		if (str[i][j] == '\0')
			return (0);
		while (str[i][j] != '\0')
		{
			if (ft_isdigit(str[i][j]) == 1)
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_if_int(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != (void *) 0)
	{
		j = 0;
		pass_space(str[i], &j);
		if (ft_strncmp(&str[i][j], "-2147483648", 20) == 0)
		{
			i++;
			continue ;
		}
		if (check_int_by_over_flow(&str[i][j]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	check_int_by_over_flow(char *str)
{
	int	after_number;
	int	before_number;
	int	i;

	after_number = 0;
	i = 0;
	pass_sign(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		before_number = after_number;
		after_number = after_number * 10 + (str[i] - '0');
		if (after_number / 10 != before_number)
			return (0);
		i++;
	}
	return (1);
}

static int	check_if_duplicate(char **str)
{
	int	int_count;
	int	*int_array;
	int	i;
	int	j;

	int_count = 0;
	int_array = get_int_array(str, &int_count);
	i = 0;
	while (i + 1 < int_count)
	{
		j = i + 1;
		while (j < int_count)
		{
			if (int_array[i] == int_array[j])
			{
				free(int_array);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(int_array);
	return (1);
}
