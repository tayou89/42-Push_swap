/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:06:28 by tayou             #+#    #+#             */
/*   Updated: 2022/11/19 17:31:37 by tayou            ###   ########.fr       */
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
/*
#include <stdio.h>

int	main()
{
	int	n;
	int	fd;

	printf("n: ");
	scanf("%d", &n);
	printf("fd: ");
	scanf("%d", &fd);
	ft_putnbr_fd(n, fd);
	return (0);
}
*/
