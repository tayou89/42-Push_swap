/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:05:06 by tayou             #+#    #+#             */
/*   Updated: 2022/11/30 06:29:35 by tayou            ###   ########.fr       */
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
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	str[200];
	int		c;
	
	scanf("%s", str);
	scanf("%d", &c);
	printf("str: %s\n", str);
	printf("c: %d\n", c);
	printf("strrchr: %s\n", strrchr(str, c));
	printf("ft_strrchr: %s\n", ft_strrchr(str, c));
	return (0);
}
*/
