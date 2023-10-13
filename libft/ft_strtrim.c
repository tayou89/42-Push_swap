/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayou <tayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:56:29 by tayou             #+#    #+#             */
/*   Updated: 2022/11/22 22:47:07 by tayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_string(char const *s1, int start_point, int end_point)
{
	char	*string;
	int		string_size;
	int		i;

	string_size = end_point - start_point + 1;
	string = (char *) malloc(sizeof(char) * string_size + 1);
	if (string == 0)
		return (0);
	i = 0;
	while (start_point <= end_point)
	{
		string[i] = s1[start_point];
		i++;
		start_point++;
	}
	string[i] = '\0';
	return (string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s1;
	int		start_point;
	int		end_point;
	int		i;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	start_point = i;
	i = ft_strlen(s1) - 1;
	while (i >= 0 && ft_strchr(set, s1[i]) != 0)
		i--;
	end_point = i;
	if (start_point > end_point)
		return (ft_strdup(""));
	trimmed_s1 = get_string(s1, start_point, end_point);
	return (trimmed_s1);
}
/*
#include <stdio.h>

int	main()
{
	char	*s1 = "";
	char	*set = " \n\t";

	printf("s1: %s\n", s1);
	printf("set: %s\n", set);
	printf("trimmed_s1: %s\n", ft_strtrim(s1, set));
	return (0);
}
*/
