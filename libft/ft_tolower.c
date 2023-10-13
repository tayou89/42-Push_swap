/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:31:07 by tayou             #+#    #+#             */
/*   Updated: 2022/11/14 22:01:57 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	int	c;

	scanf("%d", &c);
	printf("tolower: %d\n", tolower(c));
	printf("ft_tolower: %d\n", ft_tolower(c));
	return (0);
}
*/
