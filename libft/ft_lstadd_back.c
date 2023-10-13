/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:50:18 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:25:49 by tayou            ###   ########.fr       */
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
