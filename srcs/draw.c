/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrorscha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 23:03:39 by lrorscha          #+#    #+#             */
/*   Updated: 2019/12/01 23:16:37 by lrorscha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_fdf *e, t_coord src, t_coord dst)
{
	int dx;
	int dy;
	int s[2];
	int err[2];

	dx = abs(dst.x - src.x);
	dy = abs(dst.y - src.y);
	s[0] = (src.x < dst.x ? 1 : -1);
	s[1] = (src.y < dst.y ? 1 : -1);
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (src.x != dst.x || src.y != dst.y)
	{
		pixel_put(e, src.x, src.y, e->color);
		err[1] = err[0];
		if (err[1] > -dx)
		{
			err[0] -= dy;
			src.x += s[0];
		}
		if (err[1] < dy)
		{
			err[0] += dx;
			src.y += s[1];
		}
	}
}

void		draw_lines(t_fdf *e, int x, int y)
{
	t_coord		p[2];

	p[0].x = e->map[y][x].xp;
	p[0].y = e->map[y][x].yp;
	if (x < e->width - 1)
	{
		p[1].x = e->map[y][x + 1].xp;
		p[1].y = e->map[y][x + 1].yp;
		draw_line(e, p[0], p[1]);
	}
	if (y < e->height - 1)
	{
		p[1].x = e->map[y + 1][x].xp;
		p[1].y = e->map[y + 1][x].yp;
		draw_line(e, p[0], p[1]);
	}
}

void		draw_fdf(t_fdf *e)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	apply_proj(e);
	mlx_clear_window(e->mlx, e->win);
	while (y < e->height)
	{
		while (x < e->width)
		{
			draw_lines(e, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
