/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 04:56:20 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 11:09:34 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	move_left(t_mapval **map, t_raycast *rc, double step)
{
	int		next_x;
	int		next_y;

	next_x = (int)(rc->pos_x - rc->plane_x * step);
	next_y = (int)(rc->pos_y - rc->plane_y * step);
	if (map[next_x][(int)rc->pos_y].val == 0)
		rc->pos_x -= rc->plane_x * step;
	if (map[(int)rc->pos_x][next_y].val == 0)
		rc->pos_y -= rc->plane_y * step;
}

static void	move_right(t_mapval **map, t_raycast *rc, double step)
{
	int		next_x;
	int		next_y;

	next_x = (int)(rc->pos_x + rc->plane_x * step);
	next_y = (int)(rc->pos_y + rc->plane_y * step);
	if (map[next_x][(int)rc->pos_y].val == 0)
		rc->pos_x += rc->plane_x * step;
	if (map[(int)rc->pos_x][next_y].val == 0)
		rc->pos_y += rc->plane_y * step;
}

void		move(t_mapval **map, t_raycast *rc, int keycode)
{
	double	step;
	double	angle;

	step = (rc->slow) ? 0.1 : 0.5;
	angle = 0.09;
	if (keycode == UP || keycode == W)
		move_forward(map, rc, step);
	if (keycode == DOWN || keycode == S)
		move_backward(map, rc, step);
	if (keycode == A)
		move_left(map, rc, step);
	if (keycode == D)
		move_right(map, rc, step);
	if (keycode == RIGHT)
	{
		ft_rotate(&(rc->dir_x), &(rc->dir_y), -angle);
		ft_rotate(&(rc->plane_x), &(rc->plane_y), -angle);
	}
	if (keycode == LEFT)
	{
		ft_rotate(&(rc->dir_x), &(rc->dir_y), angle);
		ft_rotate(&(rc->plane_x), &(rc->plane_y), angle);
	}
}
