/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 16:19:32 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 21:24:18 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *restrict s2, const void *restrict s1, size_t n)
{
	size_t	i;

	if (s2 == s1 || n == 0)
		return (s2);
	i = 0;
	while (i < n)
	{
		((unsigned char*)s2)[i] = ((unsigned char*)s1)[i];
		i++;
	}
	return (s2);
}
