/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:35:49 by tayou             #+#    #+#             */
/*   Updated: 2022/11/21 21:02:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (i + 1 < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	dst1[] = "abcdefg";
	char	dst2[] = "abcdefg";
	char	*src = "";

	printf("dst: %s\n", dst1);
	printf("src: %s\n", src);
	printf("strlcpy return: %lu\n", strlcpy(dst1, src, strlen(dst1)));
	printf("ft_strlcpy return: %lu\n", ft_strlcpy(dst2, src, strlen(dst2)));
	printf("changed strlcpy_dst: %s\n", dst1);
	printf("changed ft_strlcpy_dst: %s\n", dst2);
	return (0);
}
*/
