/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:05:06 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:30:14 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		else
			i--;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	else
		return (0);
}
