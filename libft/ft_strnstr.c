/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:45:38 by tayou             #+#    #+#             */
/*   Updated: 2023/03/28 14:04:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check(const char *haystack, const char *needle, size_t i, size_t len)
{
	size_t	k;

	k = 0;
	while (i < len && needle[k] != '\0' && haystack[k] != '\0')
	{
		if (needle[k] == haystack[k])
		{
			i++;
			k++;
		}
		else
			return (1);
	}
	if (needle[k] == '\0')
		return (0);
	else
		return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	same_point;

	if (needle[0] == 0)
		return ((char *) haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			same_point = i;
			if (check(haystack + i, needle, i, len) == 0)
				return ((char *) haystack + same_point);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	*haystack = "food is good";
	char	*needle = "good";
	size_t	len;

	printf("haystack: %s\n", haystack);
	printf("needle: %s\n", needle);
	printf("양의 정수를 입력하십시오: ");
	scanf("%lu", &len);
	printf("strnstr: %s\n", strnstr(haystack, needle, len));
	printf("ft_strnstr: %s\n", ft_strnstr(haystack, needle, len));
	return (0);
}
*/
