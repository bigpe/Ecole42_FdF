/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 17:16:35 by ukaron            #+#    #+#             */
/*   Updated: 2019/05/27 18:21:55 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_count(const char *ss, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (ss == NULL)
		return (0);
	while (ss[i])
	{
		if (ss[i] == c && ss[i + 1] != c)
			count++;
		i++;
	}
	if (ss[0] != '\0')
		count++;
	return (count);
}

static char		*ft_word(const char *ss, char c, int *i)
{
	char	*s;
	int		k;

	s = ft_strnew(ft_strlen(ss));
	if (s == NULL)
		return (NULL);
	k = 0;
	while (ss[*i] != c && ss[*i])
	{
		s[k] = ss[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (ss[*i] == c && ss[*i])
		*i += 1;
	return (s);
}

char			**ft_strsplit(char const *ss, char c)
{
	char	**s;
	int		i;
	int		j;
	int		wrd;

	if (ss == NULL)
		return (NULL);
	wrd = ft_count(ss, c);
	s = (char**)malloc(sizeof(s) * (wrd + 2));
	if (s == NULL)
	{
		free(s);
		return (0);
	}
	i = 0;
	j = 0;
	while (ss[i] == c && ss[i])
		i++;
	while (j < wrd && ss[i])
	{
		s[j] = ft_word(ss, c, &i);
		j++;
	}
	s[j] = NULL;
	return (s);
}
