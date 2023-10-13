/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:45:39 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:24:26 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	get_number(const char *str, int *i, long long number)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		number = number * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (number);
}

int	check_if_number(const char *str, int *i)
{
	if (str[*i] >= '0' && str[*i] <= '9')
		return (1);
	else
		return (0);
}

int	check_sign(const char *str, int *i)
{
	if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (str[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	else
		return (1);
}

void	check_whitespace(const char *str, int *i)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	check_whitespace(str, &i);
	sign = check_sign(str, &i);
	if (check_if_number(str, &i) == 0)
		return (0);
	number = 0;
	number = get_number(str, &i, number);
	number *= sign;
	return ((int) number);
}
