/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 23:17:06 by lrorscha          #+#    #+#             */
/*   Updated: 2019/12/01 23:23:05 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		count_words(const char *line)
{
	int		count;
	int		i;
	int		len;
	char	lastchar;

	i = 0;
	count = 0;
	len = ft_strlen(line);
	if (len > 0)
		lastchar = line[0];
	while (i <= len)
	{
		if ((line[i] == ' ' || line[i] == '\0') && lastchar != ' ')
			count++;
		lastchar = line[i];
		i++;
	}
	return (count);
}

static void		smallest(t_fdf *e, int x, int y, int c)
{
	size_t tmp;

	if (c == 0)
	{
		tmp = abs(e->map[y][x].z);
		if ((!e->smallest && tmp != 0) || (e->smallest > tmp && tmp != 0))
			e->smallest = tmp;
	}
	else
	{
		if (!e->smallest)
			e->smallest = 1;
		while (y < e->height)
		{
			while (x < e->width)
			{
				e->map[y][x].z /= e->smallest;
				e->map[y][x].z0 /= e->smallest;
				x++;
			}
			x = 0;
			y++;
		}
	}
}

void			read_args(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	**line_split;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		line_split = ft_strsplit(line, ' ');
		while (*line_split != NULL)
		{
			fdf->map[y][x].z = ft_atoi(*line_split);
			smallest(fdf, x, y, 0);
			fdf->map[y][x].z0 = fdf->map[y][x].z;
			x++;
			line_split++;
		}
		x = 0;
		y++;
	}
	close(fd);
	smallest(fdf, 0, 0, 1);
}

static int		get_info(char *filepath, int c)
{
	int		fd;
	int		ret;
	char	*line;

	ret = 0;
	fd = open(filepath, O_RDONLY);
	if (c == 1)
	{
		while (get_next_line(fd, &line) > 0)
			ret++;
		close(fd);
	}
	else
	{
		get_next_line(fd, &line);
		ret = count_words(line);
		while (get_next_line(fd, &line) > 0)
		{
			if (count_words(line) != ret)
				die("ERROR");
		}
		close(fd);
	}
	return (ret);
}

void			parse_args(char *file, t_fdf *fdf)
{
	int index;

	index = 0;
	fdf->height = get_info(file, 1);
	fdf->width = get_info(file, 2);
	fdf->map = (t_point **)malloc(sizeof(t_point *) * fdf->height);
	while (index < fdf->height)
	{
		fdf->map[index] = (t_point *)malloc(sizeof(t_point) * fdf->width);
		index++;
	}
}
