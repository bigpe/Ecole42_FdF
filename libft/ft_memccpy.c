/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 17:48:58 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 20:59:12 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *s2, const void *s1, int c, size_t n)
{
	unsigned char	*ss2;
	unsigned char	*ss1;
	size_t			i;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		ss2[i] = ss1[i];
		if (ss1[i] == (unsigned char)c)
		{
			return (ss2 + i + 1);
		}
		i++;
	}
	return (NULL);
}
