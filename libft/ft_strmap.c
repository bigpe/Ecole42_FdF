/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:35:34 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/27 18:30:17 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fsh;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	fsh = (char*)malloc(ft_strlen(s) + 1);
	if (fsh == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		fsh[i] = f(s[i]);
		i++;
	}
	fsh[i] = '\0';
	return (fsh);
}
