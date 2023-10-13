/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:11:22 by tayou             #+#    #+#             */
/*   Updated: 2023/04/05 12:11:38 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_isspace(int c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

void	pass_space(char *str, int *i)
{
	while (ft_isspace(str[*i]) == 1)
		(*i)++;
}

void	pass_notspace(char *str, int *i)
{
	while (ft_isspace(str[*i]) == 0 && str[*i] != '\0')
		(*i)++;
}

void	pass_sign(char *str, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
		(*i)++;
}

char	*malloc_array(char **array, int i, int size)
{
	array[i] = (char *) malloc(sizeof(char) * size + 1);
	if (array[i] == (void *) 0)
	{
		free_array(array);
		exit(1);
	}
	return (array[i]);
}
