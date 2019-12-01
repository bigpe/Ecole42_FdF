/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:05:17 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 21:31:34 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ss;

	ss = (char*)s;
	i = 0;
	while (ss[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (ss[i] == c)
			return (&ss[i]);
		i--;
	}
	return (0);
}
