/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 22:19:08 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 21:43:21 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	len2;

	if (*s2 == '\0')
		return ((char*)s1);
	len2 = ft_strlen(s2);
	while (*s1 != '\0' && len >= len2)
	{
		if (*s1 == *s2 && !ft_memcmp(s1, s2, len2))
			return ((char*)s1);
		s1++;
		len--;
	}
	return (0);
}
