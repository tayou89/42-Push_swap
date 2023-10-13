/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_array_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:09:46 by tayou             #+#    #+#             */
/*   Updated: 2023/04/05 12:10:06 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	get_int_count(char **string_array);

int	*get_int_array(char **string_array, int *int_count)
{
	int	*int_array;
	int	i;

	*int_count = get_int_count(string_array);
	int_array = (int *) malloc(sizeof(int) * (*int_count));
	if (int_array == 0)
	{
		free_array(string_array);
		exit(1);
	}
	i = 0;
	while (string_array[i] != (void *) 0)
	{
		int_array[i] = ft_atoi(string_array[i]);
		i++;
	}
	return (int_array);
}

static int	get_int_count(char **string_array)
{
	int	int_count;
	int	i;

	i = 0;
	while (string_array[i] != (void *) 0)
		i++;
	int_count = i;
	return (int_count);
}
