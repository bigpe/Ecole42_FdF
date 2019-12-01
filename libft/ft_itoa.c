/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:18:04 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 20:07:00 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_isnegative(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

char			*ft_itoa(int n)
{
	char	*ss;
	int		neg;
	int		len;
	int		g;

	g = n;
	len = 1;
	neg = ft_isnegative(n);
	while (g /= 10)
		len++;
	ss = ft_strnew(len + neg);
	if (ss == NULL)
		return (NULL);
	while (len--)
	{
		if (neg)
			ss[len + neg] = -(n % 10) + '0';
		else
			ss[len + neg] = (n % 10) + '0';
		n = n / 10;
	}
	if (neg)
		ss[0] = '-';
	return (ss);
}
