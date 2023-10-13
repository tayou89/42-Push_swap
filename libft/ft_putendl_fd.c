/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:54:09 by tayou             #+#    #+#             */
/*   Updated: 2022/11/19 16:58:32 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
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
	ft_putendl_fd(s, fd);
	return (0);
}
*/
