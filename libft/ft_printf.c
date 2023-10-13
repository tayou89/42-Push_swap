/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:09:50 by tayou             #+#    #+#             */
/*   Updated: 2023/03/01 17:27:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_type(va_list ap, char character, int *print_count)
{
	if (character == 'c')
		ft_print_character(va_arg(ap, int), print_count);
	else if (character == 's')
		ft_print_string(va_arg(ap, char *), print_count);
	else if (character == 'p')
		ft_print_address(va_arg(ap, void *), print_count);
	else if (character == 'd' || character == 'i')
		ft_print_decimal(va_arg(ap, int), print_count);
	else if (character == 'u')
		ft_print_unsigned(va_arg(ap, unsigned int), print_count);
	else if (character == 'x' || character == 'X')
		ft_print_hexa(character, va_arg(ap, unsigned int), print_count);
	else if (character == '%')
		ft_print_percent(print_count);
}

int	ft_printf(const char *str, ...)
{
	int		print_count;
	va_list	ap;
	int		i;

	va_start(ap, str);
	print_count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			print_count++;
			i++;
		}
		else if (str[i] == '%')
		{
			check_type(ap, str[i + 1], &print_count);
			i += 2;
		}
	}	
	return (print_count);
}
