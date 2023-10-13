/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:02:06 by tayou             #+#    #+#             */
/*   Updated: 2022/12/01 21:17:10 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new);
		lst = lst->next;
	}
	return (new_lst);
}
/*
#include <stdio.h>

void	f(void *content)
{
	char	*s;
	size_t	i;

	s = (char *) content;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] += 'A' - 'a';
		i++;
	}
}

void	del(void *s)
{
	if (s == NULL)
		return ;
	else
		s = NULL;
}

int	main()
{
	char	s[] = "abcdefg";
	t_list	*lst;
	t_list	*new_lst;
	t_list	*copy;
	size_t	lst_count;
	size_t	i;

	lst = ft_lstnew((void *) s);
	printf("lst_count: ");
	scanf("%lu", &lst_count);
	i = 1;
	while (i < lst_count)
	{
		new_lst = ft_lstnew((void *) s);
		ft_lstadd_back(&lst, new_lst);
		i++;
	}
	i = 1;
	copy = lst;
	while (copy != NULL)
	{
		printf("original lst%lu content: %s\n", i, (char *) copy->content);
		copy = copy->next;
		i++;
	}
	new_lst = ft_lstmap(lst, (void *)f, del);
	i = 1;
	while (new_lst != NULL)
	{
		printf("new lst%lu content: %s\n", i, (char *) new_lst->content);
		new_lst = new_lst->next;
		i++;
	}
	return (0);
}
*/
