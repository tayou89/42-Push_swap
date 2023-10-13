/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:50:19 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:27:41 by tayou            ###   ########.fr       */
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
