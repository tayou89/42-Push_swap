/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:25:17 by tayou             #+#    #+#             */
/*   Updated: 2022/11/18 02:54:49 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_digit(long long number)
{
	int	i;

	i = 0;
	if (number < 0)
	{
		number *= (-1);
		i++;
	}
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

char	*fill_string(char *string, long long number, int digit)
{
	int	i;

	if (number < 0)
	{
		number *= (-1);
		string[0] = '-';
	}
	if (number == 0)
		string[0] = '0';
	i = digit;
	while (number != 0)
	{
		string[i - 1] = number % 10 + '0';
		number /= 10;
		i--;
	}
	string[digit] = '\0';
	return (string);
}

char	*ft_itoa(int n)
{
	char		*string;
	long long	number;
	int			digit;

	number = (long long) n;
	digit = get_digit(number);
	string = (char *) malloc(sizeof(char) * digit + 1);
	if (string == 0)
		return (0);
	string = fill_string(string, number, digit);
	return (string);
}
/*
#include <stdio.h>

int	main()
{
	int	n;

	printf("n: ");
	scanf("%d", &n);
	printf("ft_itoa: %s\n", ft_itoa(n));
	return (0);
}
*/
