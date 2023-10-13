/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:01:49 by tayou             #+#    #+#             */
/*   Updated: 2023/03/16 14:24:58 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

void	del(void *s)
{
	if (s == NULL)
		return ;
	else
		s = NULL;
}

int	main()
{
	char	*s = "abcdefg";
	t_list	*lst;

	lst = ft_lstnew((void *) s);
	printf("lst->content: %s\n", (char *) lst->content);
	ft_lstdelone(lst, del);
	printf("changed lst->content: %s\n", (char *) lst->content);
	return (0);
}
*/
