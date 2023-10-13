/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:45:44 by tayou             #+#    #+#             */
/*   Updated: 2023/03/01 17:29:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digit(unsigned int number)
{
	int	digit;

	digit = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		digit++;
	}
	return (digit);
}

static char	*fill_number_array(char *array, unsigned int number, int digit)
{
	int	i;

	if (number == 0)
		array[0] = '0';
	i = digit - 1;
	while (number != 0)
	{
		array[i] = number % 10 + '0';
		number /= 10;
		i--;
	}
	array[digit] = '\0';
	return (array);
}

void	ft_print_unsigned(unsigned int number, int *print_count)
{
	char	*array;
	int		digit;

	digit = get_digit(number);
	array = (char *) malloc(sizeof(char) * digit + 1);
	if (array == 0)
		return ;
	array = fill_number_array(array, number, digit);
	write(1, array, digit);
	(*print_count) += digit;
	free(array);
}
