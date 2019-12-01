/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:14:33 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 21:55:06 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*ss1;
	char	*ss2;
	int		i;
	int		j;

	ss1 = (char*)s1;
	ss2 = (char*)s2;
	if (*ss2 == '\0')
		return (ss1);
	i = 0;
	while (ss1[i] != '\0')
	{
		j = 0;
		while (ss2[j] == ss1[j + i])
		{
			if (ss2[j + 1] == '\0')
				return (ss1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
