/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 15:56:59 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/15 02:18:33 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_strclear(const char *s)
{
	int	len;
	int i;

	len = ft_strlen(s);
	i = 0;
	while (s[len - 1] == '\n' || s[len - 1] == '\t' || s[len - 1] == ' ')
		len--;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
	{
		i++;
		len--;
	}
	if (len < 0)
		return (0);
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*ss;
	int		i;
	int		j;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strclear(s);
	ss = (char*)malloc(sizeof(char) * (len + 1));
	if (ss == NULL)
		return (NULL);
	i = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		i++;
	j = 0;
	while (s[i] != '\0')
		ss[j++] = s[i++];
	j--;
	while (ss[j] == '\n' || ss[j] == ' ' || ss[j] == '\t')
		j--;
	ss[j + 1] = '\0';
	return (ss);
}
