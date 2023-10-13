/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:20:36 by tayou             #+#    #+#             */
/*   Updated: 2022/11/19 21:43:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>

int	main()
{
	char	*s1 = "111111";
	char	*s2 = "222222";
	char	*s3 = "333333";
	t_list	*list[3];
	int		size;
	int		i;

	list[0] = ft_lstnew((void *) s1);
	list[1] = ft_lstnew((void *) s2);
	list[2] = ft_lstnew((void *) s3);
	i = 0;
	while (i < 2)
	{
		list[i]->next = list[i + 1];
		i++;
	}
	size = ft_lstsize(list[0]);
	printf("list_size: %d\n", size);
	return (0);
}
*/
