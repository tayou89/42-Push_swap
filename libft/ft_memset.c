/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:33:13 by tayou             #+#    #+#             */
/*   Updated: 2022/11/16 23:15:16 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*copy_b;
	size_t			i;

	copy_b = (unsigned char *) b;
	c = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		copy_b[i] = c;
		i++;
	}
	return ((void *) copy_b);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	b[] = "abcdefg";
	char	c;
	int		len;

	printf("문자를 입력하십시오: ");
	scanf("%c", &c);
	printf("길이(양의 정수)를 입력하십시오: ");
	scanf("%d", &len);
	printf("원본: %s\n", b);
	printf("memset: %s\n", memset(b, c, len));
	printf("ft_memset: %s\n", ft_memset(b, c, len));
	return (0);
}
*/
