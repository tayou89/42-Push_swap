/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:22:52 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:29:59 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*changed_s;
	unsigned int	i;
	unsigned int	s_len;

	if (s[0] == 0)
	{
		changed_s = (char *) malloc(sizeof(char));
		if (changed_s == 0)
			return (0);
		changed_s[0] = '\0';
		return (changed_s);
	}
	s_len = ft_strlen(s);
	changed_s = (char *) malloc(sizeof(char) * s_len + 1);
	if (changed_s == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		changed_s[i] = f(i, s[i]);
		i++;
	}
	changed_s[i] = '\0';
	return (changed_s);
}
