/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:50:31 by tayou             #+#    #+#             */
/*   Updated: 2023/03/01 17:28:23 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_hexa_digit(unsigned int number)
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

static void	get_hexa_string(unsigned int n, char *hexa_string, int hexa_digit)
{
	int		i;
	char	*hexa;

	hexa = "0123456789abcdef";
	i = hexa_digit - 1;
	while (n != 0)
	{
		hexa_string[i] = hexa[n % 16];
		n /= 16;
		i--;
	}
	hexa_string[hexa_digit] = '\0';
}

static void	change_toupper(char *hexa_string)
{
	int	i;

	i = 0;
	while (hexa_string[i] != '\0')
	{
		if (hexa_string[i] >= 'a' && hexa_string[i] <= 'z')
			hexa_string[i] -= 32;
		i++;
	}
}

void	ft_print_hexa(char character, unsigned int number, int *print_count)
{
	char	*hexa_string;
	int		hexa_digit;

	if (number == 0)
	{
		write(1, "0", 1);
		(*print_count)++;
		return ;
	}
	hexa_digit = get_hexa_digit(number);
	hexa_string = (char *) malloc(sizeof(char) * hexa_digit + 1);
	if (hexa_string == 0)
		return ;
	get_hexa_string(number, hexa_string, hexa_digit);
	if (character == 'X')
		change_toupper(hexa_string);
	write(1, hexa_string, hexa_digit);
	(*print_count) += hexa_digit;
	free(hexa_string);
}
