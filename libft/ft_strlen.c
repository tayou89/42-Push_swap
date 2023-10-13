/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 00:05:51 by tayou             #+#    #+#             */
/*   Updated: 2022/11/14 22:17:09 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	*s;

	s = "abc def";
	printf("%s\n", s);
	printf("strlen: %lu\n", strlen(s));
	printf("ft_strlen: %lu\n", ft_strlen(s));
	return (0);
}
*/
