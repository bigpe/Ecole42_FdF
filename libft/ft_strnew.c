/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:46:19 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 21:42:30 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*ss;

	ss = (char*)malloc(sizeof(char) * size + 1);
	if (ss == NULL)
		return (NULL);
	ft_bzero(ss, size + 1);
	return (ss);
}
