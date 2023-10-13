/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:52:33 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:27:19 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*copy_s;
	unsigned char	copy_c;
	size_t			i;

	copy_s = (unsigned char *) s;
	copy_c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (copy_s[i] == copy_c)
			return ((void *) &copy_s[i]);
		else
			i++;
	}
	return (NULL);
}
