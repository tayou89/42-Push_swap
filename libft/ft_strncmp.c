/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:33:21 by tayou             #+#    #+#             */
/*   Updated: 2022/11/21 21:17:11 by tayou            ###   ########.fr       */
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
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	*s1 = "";
	char	*s2 = "abcde";
	size_t	n;

	scanf("%lu", &n);
	printf("strncmp: %d\n", strncmp(s1, s2, n));
	printf("ft_strncmp: %d\n", ft_strncmp(s1, s2, n));
	return (0);
}
*/
