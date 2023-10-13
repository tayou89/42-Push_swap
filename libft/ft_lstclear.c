/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:35:17 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:26:17 by tayou            ###   ########.fr       */
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
