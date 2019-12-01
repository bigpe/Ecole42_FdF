/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:48:11 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/27 18:50:07 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fsh;

	if (s == NULL || f == NULL)
		return (NULL);
	fsh = (char*)malloc(ft_strlen(s) + 1);
	if (fsh == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		fsh[i] = f(i, s[i]);
		i++;
	}
	fsh[i] = '\0';
	return (fsh);
}
