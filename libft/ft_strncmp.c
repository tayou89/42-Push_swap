/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:33:21 by tayou             #+#    #+#             */
/*   Updated: 2023/03/28 21:53:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*copy_s1;
	unsigned char	*copy_s2;

	copy_s1 = (unsigned char *) s1;
	copy_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n && copy_s1[i] != '\0' && copy_s2[i] != '\0')
	{
		if (copy_s1[i] == copy_s2[i])
			i++;
		else
			break ;
	}
	if (i == n)
		i--;
	return (copy_s1[i] - copy_s2[i]);
}
