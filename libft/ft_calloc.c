/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:43:39 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:24:48 by tayou            ###   ########.fr       */
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
