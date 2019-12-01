/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:29:26 by ukaron            #+#    #+#             */
/*   Updated: 2019/12/01 23:02:38 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <math.h>
# include "mlx.h"
# include <fcntl.h>
# define WIN_X 1000
# define WIN_Y 1000
# define CZ 0xFFFFFF
# define CX 0x0E50BA
# define CC 0xC60707
# define CV 0x8c0fc6
# define CB 0xe8930b
# define CN 0x04963e
# define BUFF_SIZE 1

typedef struct			s_point
{
	int					z;
	int					z0;
	int					xp;
	int					yp;
}						t_point;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	t_point				**map;
	t_coord				scale;
	t_coord				pos;
	int					height;
	int					width;
	int					alt;
	size_t				smallest;
	int					color;
}						t_fdf;

int						die(char *mes);
int						get_next_line(int fd, char **line);
void					read_args(char *file, t_fdf *fdf);
void					draw_fdf(t_fdf *e);
void					draw_lines(t_fdf *e, int x, int y);
void					parse_args(char *file, t_fdf *fdf);
void					pixel_put(t_fdf *e, int x, int y, int color);
void					apply_proj(t_fdf *e);
int						event_key(int keycode, t_fdf *e);
void					apply_height(t_fdf *e, int c);

#endif
