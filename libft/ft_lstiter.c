/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:19:27 by tayou             #+#    #+#             */
/*   Updated: 2023/04/06 18:26:46 by tayou            ###   ########.fr       */
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
