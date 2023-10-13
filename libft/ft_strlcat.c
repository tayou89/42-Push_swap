/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:55:38 by tayou             #+#    #+#             */
/*   Updated: 2022/11/17 23:27:54 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	dst_index;
	size_t	src_index;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	dst_index = dst_len;
	src_index = 0;
	while (dst_index < size - 1 && src[src_index] != '\0')
	{
		dst[dst_index] = src[src_index];
		dst_index++;
		src_index++;
	}
	dst[dst_index] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	dst1[100] = "apple";
	char	dst2[100] = "apple";
	char	*src = " is good";
	size_t	dstsize;

	printf("dst: %s\n", dst1);
	printf("src: %s\n", src);
	printf("dstsize: ");
	scanf("%lu", &dstsize);
	printf("strlcat return: %lu\n", strlcat(dst1, src, dstsize));
	printf("ft_strlcat return: %lu\n", ft_strlcat(dst2, src, dstsize));
	printf("strlcat dst: %s\n", dst1);
	printf("ft_strlcat dst: %s\n", dst2);
	return (0);
}
*/
