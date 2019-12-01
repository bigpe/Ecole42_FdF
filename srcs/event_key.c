/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 23:20:19 by ukaron            #+#    #+#             */
/*   Updated: 2019/12/01 23:28:04 by ukaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		event_key_next(int keycode, t_fdf *e)
{
	if (keycode == 78)
	{
		e->scale.x -= 1;
		e->scale.y += 1;
	}
	if (keycode == 1)
	{
		e->alt -= 1;
		apply_height(e, -1);
	}
	if (keycode == 49)
	{
		if (e->color == CZ)
			e->color = CX;
		else if (e->color == CX)
			e->color = CC;
		else if (e->color == CC)
			e->color = CV;
		else if (e->color == CV)
			e->color = CB;
		else
			e->color = CZ;
	}
	draw_fdf(e);
	return (1);
}

int		event_key(int keycode, t_fdf *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		e->pos.x += 30;
	if (keycode == 125)
		e->pos.y += 30;
	if (keycode == 123)
		e->pos.x -= 30;
	if (keycode == 126)
		e->pos.y -= 30;
	if (keycode == 13)
	{
		e->alt += 1;
		apply_height(e, 1);
	}
	if (keycode == 69)
	{
		e->scale.x += 1;
		e->scale.y -= 1;
	}
	return (event_key_next(keycode, e));
}

int		event_mouse(int button, int x, int y, t_fdf *e)
{
	if (button == 1 && x && y)
	{
		if (e->color == CZ)
			e->color = CX;
		else if (e->color == CX)
			e->color = CC;
		else if (e->color == CC)
			e->color = CV;
		else if (e->color == CV)
			e->color = CB;
		else if (e->color == CB)
			e->color = CN;
		else
			e->color = CZ;
		draw_fdf(e);
	}
	return (1);
}
