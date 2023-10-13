/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:59:23 by tayou             #+#    #+#             */
/*   Updated: 2023/03/12 08:04:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pass_notspace(char *str, int *i)
{
	while (ft_isspace(str[*i]) == 0 && str[*i] != '\0')
		(*i)++;
}

static int	get_string_count(char **argv)
{
	int	i;
	int	j;
	int	array_count;

	array_count = 0;
	i = 1;
	while (argv[i] != (void *) 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			pass_space(argv[i], &j);
			if (argv[i][j] == '\0')
				break ;
			pass_notspace(argv[i], &j);
			array_count++;
		}
		i++;
	}
	return (array_count);
}

static int	get_array_size(char *str, int *i)
{
	int	size;
	int	start_point;
	int	end_point;

	size = 0;
	start_point = *i;
	pass_space(str, i);
	if (str[*i] == '\0')
		return (size);
	pass_notspace(str, i);
	end_point = *i - 1;
	size = end_point - start_point + 1;
	return (size);
}

static char	*malloc_array(char **array, int	i, int size)
{
	array[i] = (char *) malloc(sizeof(char) * size + 1);
	if (array[i] == (void *) 0)
	{
		free_array(array);
		exit(1);
	}
	return (array[i]);
}

static char	*fill_array(char *array, char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

static char	**get_array(char **array, char **argv)
{
	int	i;
	int	j;
	int	k;
	int	size;

	k = 0;
	i = 1;
	while (argv[i] != (void *) 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			size = get_array_size(argv[i], &j);
			if (size == 0)
				continue ;
			array[k] = malloc_array(array, k, size);
			array[k] = fill_array(array[k], &argv[i][j-size], size);
			k++;
		}
		i++;
	}
	return (array);
}

char	**get_string_array(char **argv)
{
	char	**string_array;
	int		string_count;

	string_count = get_string_count(argv);
	if (string_count == 0)
		exit(1);
	string_array = (char **) malloc(sizeof(char *) * (string_count + 1));
	if (string_array == 0)
		exit(1);
	string_array = get_array(string_array, argv);
	string_array[string_count] = 0;
	return (string_array);
}
