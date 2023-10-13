/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:56:12 by tayou             #+#    #+#             */
/*   Updated: 2022/11/14 22:09:41 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*copy_s1;
	const unsigned char	*copy_s2;
	size_t				i;

	copy_s1 = (const unsigned char *) s1;
	copy_s2 = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (copy_s1[i] == copy_s2[i])
			i++;
		else
			return (copy_s1[i] - copy_s2[i]);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	*s1 = "abcdefg";
	char	*s2 = "abcfefg";
	size_t	n;

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	scanf("%lu", &n);
	printf("memcmp: %d\n", memcmp(s1, s2, n));
	printf("ft_memcmp: %d\n", ft_memcmp(s1, s2, n));
	return (0);
}
*/
