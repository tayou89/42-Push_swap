/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:41:02 by tayou             #+#    #+#             */
/*   Updated: 2022/11/19 16:58:20 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/*
#include <stdio.h>

int	main()
{
	char	s[] = "abcdefg";
	int		fd;

	printf("s: %s\n", s);
	printf("fd: ");
	scanf("%d", &fd);
	ft_putstr_fd(s, fd);
	printf("\n");
	return (0);
}
*/
