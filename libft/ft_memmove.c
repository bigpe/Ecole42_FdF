/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:30:29 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 21:27:11 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	if (ss1 == ss2)
		return (s1);
	if (s2 < s1)
	{
		ss2 = (unsigned char*)s2 + n - 1;
		ss1 = s1 + n - 1;
		while (n--)
			*ss1-- = *ss2--;
	}
	else
	{
		while (n--)
			*ss1++ = *ss2++;
	}
	return (s1);
}
