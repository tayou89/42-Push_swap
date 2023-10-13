/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:43:39 by tayou             #+#    #+#             */
/*   Updated: 2022/11/17 22:28:17 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;

	memory = (char *) malloc(sizeof(char) * count * size);
	if (memory == 0)
		return (0);
	ft_memset(memory, 0, count * size);
	return (memory);
}
/*
#include <stdio.h>

int	main()
{
	size_t	count;
	size_t	size;
	int		*test1;
	int		*test2;

	printf("count: ");
	scanf("%lu", &count);
	printf("size: ");
	scanf("%lu", &size);
	test1 = (int *) calloc(count, size);
	test2 = (int *) ft_calloc(count, size);
	printf("calloc: %d\n", *test1);
	printf("ft_calloc: %d\n", *test2);
	free(test1);
	free(test2);

	return (0);
}
*/
