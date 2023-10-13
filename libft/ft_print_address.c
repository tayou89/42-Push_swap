/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:42:27 by tayou             #+#    #+#             */
/*   Updated: 2023/03/01 17:27:30 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_hexa_digit(uintptr_t number)
{
	int	digit;

	digit = 0;
	while (number != 0)
	{
		number /= 16;
		digit++;
	}
	return (digit);
}

static void	get_hexa_string(uintptr_t number, char *hexa_string, int hexa_digit)
{
	int		i;
	char	*hexa;

	hexa = "0123456789abcdef";
	i = hexa_digit - 1;
	while (number != 0)
	{
		hexa_string[i] = hexa[number % 16];
		number /= 16;
		i--;
	}
	hexa_string[hexa_digit] = '\0';
}

void	ft_print_address(void *address, int *print_count)
{
	uintptr_t	number;
	int			hexa_digit;
	char		*hexa_string;

	write(1, "0x", 2);
	(*print_count) += 2;
	if (address == NULL)
	{
		write(1, "0", 1);
		(*print_count)++;
		return ;
	}
	number = (uintptr_t) address;
	hexa_digit = get_hexa_digit(number);
	hexa_string = (char *) malloc(sizeof(char) * (hexa_digit) + 1);
	if (hexa_string == 0)
		return ;
	get_hexa_string(number, hexa_string, hexa_digit);
	write(1, hexa_string, hexa_digit);
	(*print_count) += hexa_digit;
	free(hexa_string);
}
