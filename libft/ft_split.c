/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:28:26 by tayou             #+#    #+#             */
/*   Updated: 2023/03/12 06:30:32 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_array_size(char const *s, char c)
{
	int	i;
	int	array_size;

	array_size = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		array_size++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (array_size);
}

char	**free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

char	*fill_array(char *array, char const *s, int start_point, int end_point)
{
	int	i;

	i = 0;
	while (start_point <= end_point)
	{
		array[i] = s[start_point];
		start_point++;
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**get_array(char **array, char const *s, char c)
{
	int		i;
	int		k;
	int		start;
	int		end;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	k = 0;
	while (s[i] != '\0')
	{
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		end = i - 1;
		array[k] = (char *) malloc(sizeof(char) * (end - start + 1) + 1);
		if (array[k] == 0)
			return (free_array(array));
		array[k] = fill_array(array[k], s, start, end);
		while (s[i] == c && s[i] != '\0')
			i++;
		k++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		array_size;

	if (s[0] == '\0')
	{
		array = (char **) malloc(sizeof(char *) * 1);
		if (array == 0)
			return (0);
		array[0] = 0;
		return (array);
	}
	array_size = get_array_size(s, c);
	array = (char **) malloc(sizeof(char *) * (array_size + 1));
	if (array == 0)
		return (0);
	array = get_array(array, s, c);
	if (array == 0)
		return (0);
	array[array_size] = 0;
	return (array);
}
/*
#include <stdio.h>

int	main()
{
	char	*s = "\0    He   is   a   good   man ";
	char	c;
	char	**string_array;
	int		i;

	printf("s: %s\n", s);
	printf("c: ");
	scanf("%c", &c);
	string_array = ft_split(s, c);
	i = 0;
	while (string_array[i] != NULL)
	{
		printf("array[%d]: %s\n", i, string_array[i]);
		i++;
	}
	return (0);
}
*/
