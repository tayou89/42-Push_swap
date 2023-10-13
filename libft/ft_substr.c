/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:15:09 by tayou             #+#    #+#             */
/*   Updated: 2023/01/25 14:52:35 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size(size_t start, size_t s_len, size_t len)
{
	size_t	actual_size;
	size_t	necessary_size;

	if (len == 0 || s_len <= start)
	{
		actual_size = 0;
		return (actual_size);
	}
	necessary_size = s_len - start;
	if (necessary_size <= len)
		actual_size = necessary_size;
	else
		actual_size = len;
	return (actual_size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;
	size_t	size;
	size_t	i;

	s_len = ft_strlen(s);
	size = get_size(start, s_len, len);
	substring = (char *) malloc(sizeof(char) * size + 1);
	if (substring == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		substring[i] = s[start];
		start++;
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
