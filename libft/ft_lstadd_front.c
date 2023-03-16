/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:58:44 by tayou             #+#    #+#             */
/*   Updated: 2023/03/16 13:50:32 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main()
{
	char	*s = "abcdefg";
	char	*b = "zzzzzzz";
	t_list	*lst;
	t_list	*new;
	int		i;

	lst = ft_lstnew((void *) s);
	new = ft_lstnew((void *) b);
	printf("lst->content: %s\n", (char *) lst->content);
	printf("new->content: %s\n", (char *) new->content);
	ft_lstadd_front(&lst, new);
	i = 1;
	while (lst != NULL)
	{
		printf("lst%d->content: %s\n", i, (char *) lst->content);
		lst = lst->next;
		i++;
	}
	return (0);
}
*/
