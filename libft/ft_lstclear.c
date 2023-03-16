/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:35:17 by tayou             #+#    #+#             */
/*   Updated: 2023/03/16 14:27:15 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		copy = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = copy;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

void	del(void *content)
{
	if (content == NULL)
		return ;
	content = NULL;
}

int	main()
{
	t_list	*lst;
	t_list	*new;
	size_t		i;
	size_t		lst_count;

	lst = ft_lstnew((void *) 1);
	printf("lst_count: ");
	scanf("%lu", &lst_count);
	i = 2;
	while (i <= lst_count)
	{
		new = ft_lstnew((void *) i);
		ft_lstadd_back(&lst, new);
		i++;
	}
	i = 1;
	while (lst != NULL)
	{
		printf("lst%lu->content: %lu\n", i, (size_t) lst->content);
		lst = lst->next;
		i++;
	}
	ft_lstclear(&lst, del);
	while (lst != NULL)
	{
		printf("lst%lu->content: %lu\n", i, (size_t) lst->content);
		lst = lst->next;
		i++;
	}
	return (0);
}
*/
