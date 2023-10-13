/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:37:36 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:29:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	new_string = (char *) malloc(sizeof(char) * total_len + 1);
	if (new_string == 0)
		return (0);
	while (*s1 != '\0')
	{
		*new_string = *s1;
		s1++;
		new_string++;
	}
	while (*s2 != '\0')
	{
		*new_string = *s2;
		s2++;
		new_string++;
	}
	*new_string = '\0';
	return (new_string - s1_len - s2_len);
}
