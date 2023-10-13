/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 23:14:47 by tayou             #+#    #+#             */
/*   Updated: 2022/11/22 20:48:21 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char) c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *) s);
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
	printf("strchr: %s\n", strchr(str, c));
	printf("ft_strchr: %s\n", ft_strchr(str, c));
	return (0);
}
*/
