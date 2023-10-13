/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:33:13 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:27:47 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy_b;
	size_t			i;

	copy_b = (unsigned char *) b;
	c = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		copy_b[i] = c;
		i++;
	}
	return ((void *) copy_b);
}
