/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:58:52 by tayou             #+#    #+#             */
/*   Updated: 2023/03/28 13:45:09 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *) malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}
/*
#include <stdio.h>

int	main()
{
	char	*s = "abcdefg";
	t_list	*new_list;

	printf("s: %s\n", s);
	new_list = ft_lstnew((void *) s);
	printf("new_list->content: %s\n", (char *) new_list->content);
	printf("new_list->next: %s\n", (char *) new_list->next);
	return (0);
}
*/
