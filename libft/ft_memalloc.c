/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:04:04 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/23 20:28:53 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ss;

	ss = (void*)malloc(sizeof(void) * size);
	if (ss == NULL)
		return (NULL);
	ft_bzero(ss, size);
	return (ss);
}
