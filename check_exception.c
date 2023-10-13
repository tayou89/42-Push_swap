/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exception.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:51:37 by tayou             #+#    #+#             */
/*   Updated: 2023/03/12 08:05:25 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pass_sign(char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
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

static int	check_if_int(char **str)
{
	long long	number;
	long long	int_max;
	long long	int_min;
	int			i;

	int_max = 2147483647;
	int_min = -2147483648;
	i = 0;
	while (str[i] != (void *) 0)
	{
		number = ft_atoll(str[i]);
		if (number < int_min || number > int_max)
			return (0);
		else
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

static int	check_error(char **str)
{
	if (check_if_number(str) == 0 || check_if_int(str) == 0 ||
		check_if_duplicate(str) == 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	else
		return (0);
}

void	check_exception(int argc, char **argv)
{
	char	**string_array;

	if (argc <= 1)
		exit(1);
	string_array = get_string_array(argv);
	if (check_error(string_array) == 1)
	{
		free_array(string_array);
		exit(2);
	}
	else
		free_array(string_array);
}
