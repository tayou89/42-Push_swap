/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:19:27 by tayou             #+#    #+#             */
/*   Updated: 2022/11/20 18:34:52 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*copy;

	if (lst == NULL || f == NULL)
		return ;
	copy = lst;
	while (copy != NULL)
	{
		f(copy->content);
		copy = copy->next;
	}
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

int	main()
{
	char	s[] = "abcdefg";
	t_list	*lst;
	t_list	*new;
	t_list	*copy;
	size_t	lst_count;
	size_t	i;

	lst = ft_lstnew((void *) s);
	printf("lst_count: ");
	scanf("%lu", &lst_count);
	i = 1;
	while (i < lst_count)
	{
		new = ft_lstnew((void *) s);
		ft_lstadd_back(&lst, new);
		i++;
	}
	copy = lst;
	i = 1;
	while (copy != NULL)
	{
		printf("Before lst%lu: %s\n", i, (char *) copy->content);
		copy = copy->next;
		i++;
	}
	ft_lstiter(lst, f);
	copy = lst;
	i = 1;
	while (copy != NULL)
	{
		printf("After lst%lu: %s\n", i, (char *) copy->content);
		copy = copy->next;
		i++;
	}
	return (0);
}
*/
