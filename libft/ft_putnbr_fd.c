/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:06:28 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:28:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	number;
	char		remainder;

	number = (long long) n;
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number *= (-1);
	}
	remainder = number % 10 + '0';
	number /= 10;
	if (number != 0)
		ft_putnbr_fd((int) number, fd);
	ft_putchar_fd(remainder, fd);
}
