/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:43:07 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:29:19 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy_s1;
	int		s1_size;
	int		i;

	s1_size = ft_strlen(s1);
	copy_s1 = (char *) malloc(sizeof(char) * s1_size + 1);
	if (copy_s1 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		copy_s1[i] = s1[i];
		i++;
	}
	copy_s1[i] = '\0';
	return (copy_s1);
}
