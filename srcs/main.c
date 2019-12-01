/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:31:07 by ukaron            #+#    #+#             */
/*   Updated: 2019/12/01 23:26:15 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		init_fdf(t_fdf *e)
{
	if ((e->mlx = mlx_init()) == (void *)0)
		die("ERROR: Wrong file");
	e->scale.x = 30;
	e->scale.y = -30;
	e->pos.x = 400;
	e->pos.y = 400;
	e->alt = 1;
	e->color = CZ;
}

int				valid_file(char *file)
{
	int	valid;
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		valid = 0;
	else
		valid = 1;
	close(fd);
	return (valid);
}

static void		recalc_scale(t_fdf *e)
{
	while (e->scale.x * e->width > WIN_X && e->scale.x > 0)
		e->scale.x -= 1;
	while (e->scale.y * e->height < -WIN_Y && e->scale.y < 0)
		e->scale.y += 1;
	if (abs(e->scale.x) < abs(e->scale.y))
		e->scale.y = -(e->scale.x);
	else
		e->scale.x = -(e->scale.y);
}

void			pixel_put(t_fdf *e, int x, int y, int color)
{
	mlx_pixel_put(e->mlx, e->win, e->pos.x + x, e->pos.y + y, color);
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		die("ERROR");
	if (ac == 2 && valid_file(av[1]))
	{
		init_fdf(fdf);
		parse_args(av[1], fdf);
		read_args(av[1], fdf);
		recalc_scale(fdf);
		fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, "fdf");
		if (fdf->win == (void *)0)
			die("ERROR");
		draw_fdf(fdf);
		mlx_key_hook(fdf->win, event_key, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		die("Error: need a map");
	return (0);
}
