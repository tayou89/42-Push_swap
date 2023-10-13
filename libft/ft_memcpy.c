/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:28 by tayou             #+#    #+#             */
/*   Updated: 2022/11/14 22:08:57 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t			i;
	unsigned char	*copy_dst;

	copy_dst = (unsigned char *) dst;
	if (dst == NULL && src == NULL)
		return ((void *) NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return ((void *) copy_dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	int		src[] = {1, 2, 3, 4};
	int		dst1[] = {5, 6, 7, 8};
	int		dst2[] = {5, 6, 7, 8};
	int		i;
	size_t	n;

	printf("positive integer: ");
	scanf("%lu", &n);
	memcpy(dst1, src, n);
	ft_memcpy(dst2, src, n);
	printf("src: ");
	i = 0;
	while (i < 4)
	{
		printf("%d", src[i]);
		i++;
	}
	printf("\n");
	printf("memcpy: ");
	i = 0;
	while (i < 4)
	{
		printf("%d", dst1[i]);
		i++;
	}
	printf("\n");
	printf("ft_memcpy: ");
	i = 0;
	while (i < 4)
	{
		printf("%d", dst2[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
