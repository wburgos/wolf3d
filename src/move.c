/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 04:56:20 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 06:23:46 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf.h"

static void	move_forward(t_mapval **map, t_raycast *rc, double step)
{
	int		next_x;
	int		next_y;

	next_x = (int)(rc->pos_x + rc->dir_x * step);
	next_y = (int)(rc->pos_y + rc->dir_y * step);
	if (map[next_x][(int)rc->pos_y].val == 0)
		rc->pos_x += rc->dir_x * step;
	if (map[(int)rc->pos_x][next_y].val == 0)
		rc->pos_y += rc->dir_y * step;
}

static void	move_backward(t_mapval **map, t_raycast *rc, double step)
{
	int		next_x;
	int		next_y;

	next_x = (int)(rc->pos_x - rc->dir_x * step);
	next_y = (int)(rc->pos_y - rc->dir_y * step);
	if (map[next_x][(int)rc->pos_y].val == 0)
		rc->pos_x -= rc->dir_x * step;
	if (map[(int)rc->pos_x][next_y].val == 0)
		rc->pos_y -= rc->dir_y * step;
}

static void	rotate_vector(double *dir_x, double *dir_y, double angle)
{
	double	tmp;

	tmp = *dir_x;
	*dir_x = *dir_x * cos(angle) - *dir_y * sin(angle);
	*dir_y = tmp * sin(angle) + *dir_y * cos(angle);
}

void		move(t_mapval **map, t_raycast *rc, int keycode)
{
	double	step;
	double	angle;

	step = 0.5;
	angle = 0.1;
	if (keycode == UP)
		move_forward(map, rc, step);
	if (keycode == DOWN)
		move_backward(map, rc, step);
	if (keycode == RIGHT)
	{
		rotate_vector(&(rc->dir_x), &(rc->dir_y), -angle);
		rotate_vector(&(rc->plane_x), &(rc->plane_y), -angle);
	}
	if (keycode == LEFT)
	{
		rotate_vector(&(rc->dir_x), &(rc->dir_y), angle);
		rotate_vector(&(rc->plane_x), &(rc->plane_y), angle);
	}
}
