/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:14:31 by tayou             #+#    #+#             */
/*   Updated: 2022/11/16 20:18:24 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <strings.h>

int	main()
{
	char	s1[] = "abcdefg";
	char	s2[] = "abcdefg";
	size_t	n;

	printf("숫자를 입력하십시오: ");
	scanf("%lu", &n);
	printf("원본 문자열: %s\n", s1);
	bzero(s1, n);
	ft_bzero(s2, n);
	printf("bzero: %s\n", s1);
	printf("ft_bzero: %s\n", s2);
	return (0);
}
*/
