/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:44:10 by tayou             #+#    #+#             */
/*   Updated: 2023/03/01 17:28:06 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(long long number)
{
	int	digit;

	digit = 0;
	if (number < 0)
	{
		number *= (-1);
		digit++;
	}
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		digit++;
	}
	return (digit);
}

static char	*fill_number_array(char *number_array, long long number, int digit)
{
	int	i;

	if (number < 0)
	{
		number *= (-1);
		number_array[0] = '-';
	}
	if (number == 0)
		number_array[0] = '0';
	i = digit - 1;
	while (number != 0)
	{
		number_array[i] = number % 10 + '0';
		number /= 10;
		i--;
	}
	number_array[digit] = '\0';
	return (number_array);
}

void	ft_print_decimal(int n, int *print_count)
{
	char		*number_array;
	long long	number;
	int			digit;

	number = (long long) n;
	digit = get_digit(number);
	number_array = (char *) malloc(sizeof(char) * digit + 1);
	if (number_array == 0)
		return ;
	number_array = fill_number_array(number_array, number, digit);
	write(1, number_array, digit);
	(*print_count) += digit;
	free(number_array);
}
