/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:53:31 by tayou             #+#    #+#             */
/*   Updated: 2022/11/19 16:27:13 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	int	c;

	scanf("%d", &c);
	printf("toupper: %d\n", toupper(c));
	printf("ft_toupper:%d\n", ft_toupper(c));
	return (0);
}
*/
