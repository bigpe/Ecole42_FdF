/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 19:14:43 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/27 18:41:00 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*clst;

	nlst = f(lst);
	if (lst == NULL || f == NULL)
		return (NULL);
	clst = nlst;
	while (lst->next)
	{
		lst = lst->next;
		clst->next = f(lst);
		if (clst->next == NULL)
			return (NULL);
		clst = clst->next;
	}
	return (nlst);
}
