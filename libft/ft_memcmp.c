/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:56:12 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:27:25 by tayou            ###   ########.fr       */
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
