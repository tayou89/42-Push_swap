/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:50:19 by tayou             #+#    #+#             */
/*   Updated: 2022/11/30 07:21:43 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copy_dst;
	unsigned char	*copy_src;

	copy_dst = (unsigned char *) dst;
	copy_src = (unsigned char *) src;
	if (copy_dst == copy_src)
		return (dst);
	if (copy_dst < copy_src)
	{
		while (len--)
			*copy_dst++ = *copy_src++;
	}
	else
	{
		copy_dst += (len - 1);
		copy_src += (len - 1);
		while (len--)
			*copy_dst-- = *copy_src--;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	src1[100];
	char	src2[100];

	memset(src1, 0, sizeof(src1));
	memset(src2, 0, sizeof(src2));
	strcpy(src1, "abcdefg");
	strcpy(src2, "abcdefg");
	printf("src: %s\n", src1);
	memmove(src1 + 2, src1, strlen(src1));
	printf("memmove: %s\n", src1);
	ft_memmove(src2 + 2, src2, strlen(src2));
	printf("ft_memmove: %s\n", src2);
	return (0);
}
*/
