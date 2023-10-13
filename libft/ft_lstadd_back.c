/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:50:18 by tayou             #+#    #+#             */
/*   Updated: 2023/03/28 14:04:05 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy_lst;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	copy_lst = *lst;
	while (copy_lst->next != NULL)
		copy_lst = copy_lst->next;
	copy_lst->next = new;
}
/*
#include <stdio.h>

int	main()
{
	t_list	*lst = ((void *) 0);
	t_list	*new;
	int		size;
	t_list	*copy;
	char	*s[4];;
	int		i;

	s[0] = "11111";
	s[1] = "22222";
	s[2] = "33333";
	s[3] = "new";
	lst = ft_lstnew((void *) s[0]);
	copy = lst;
	i = 1;
	while (i < 3)
	{
		copy->next = ft_lstnew((void *) s[i]);
		copy = copy->next;
		i++;
	}
	new = ft_lstnew((void *) "new");
	size = ft_lstsize(lst);
	printf("before list_size: %d\n", size);
	ft_lstadd_back(&lst, new);
	size = ft_lstsize(lst);
	printf("after list_size: %d\n", size);
	return (0);
}
*/
