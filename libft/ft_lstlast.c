/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:37:06 by tayou             #+#    #+#             */
/*   Updated: 2023/03/08 14:56:34 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main()
{
	char	*s1 = "111111";
	char	*s2 = "222222";
	char	*s3 = "333333";
	t_list	*list[3];
	t_list	*last_list;
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
	last_list = ft_lstlast(list[0]);
	printf("last_list->content: %s\n", (char *) last_list->content);
	return (0);
}
*/
