/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:19:14 by tayou             #+#    #+#             */
/*   Updated: 2022/11/19 16:21:31 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (s[0] == 0)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>

void	f(unsigned int i, char *c)
{
	int	remainder;

	remainder = i % 2;
	if (remainder == 0)
		*c = 'z';
}

int	main()
{
	char	s[] = "abcdefg";

	printf("s: %s\n", s);
	ft_striteri(s, f);
	printf("changed s: %s\n", s);
	return (0);
}
*/
