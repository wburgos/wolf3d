/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wolf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 00:20:48 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 03:44:20 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "wolf.h"

static void	ray_steps(t_raycast *rc)
{
	rc->deltadist_x = sqrt(1 + (rc->raydir_y * rc->raydir_y)
		/ (rc->raydir_x * rc->raydir_x));
	rc->deltadist_y = sqrt(1 + (rc->raydir_x * rc->raydir_x)
		/ (rc->raydir_y * rc->raydir_y));
	if (rc->raydir_x < 0)
	{
		rc->step_x = -1;
		rc->sidedist_x = (rc->raypos_x - rc->map_x) * rc->deltadist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->sidedist_x = (rc->map_x + 1 - rc->raypos_x) * rc->deltadist_x;
	}
	if (rc->raydir_y < 0)
	{
		rc->step_y = -1;
		rc->sidedist_y = (rc->raypos_y - rc->map_y) * rc->deltadist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->sidedist_y = (rc->map_y + 1 - rc->raypos_y) * rc->deltadist_y;
	}
}

static void	ray_calculations(int x, t_raycast *rc)
{
	rc->camera_x = 2 * x / (2 * WIN_WIDTH) - 1;
	rc->raypos_x = rc->pos_x;
	rc->raypos_y = rc->pos_y;
	rc->raydir_x = rc->dir_x + rc->plane_x * rc->camera_x;
	rc->raydir_y = rc->dir_y + rc->plane_y * rc->camera_x;
	rc->map_x = (int)rc->raypos_x;
	rc->map_y = (int)rc->raypos_y;
	ray_steps(rc);
	rc->hit = 0;
}

static void	launch_ray(t_raycast *rc, t_env *e)
{
	while (rc->hit == 0)
	{
		if (rc->sidedist_x < rc->sidedist_y)
		{
			rc->sidedist_x += rc->deltadist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->sidedist_y += rc->deltadist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (e->map[rc->map_x][rc->map_y].val > 0)
			rc->hit = 1;
	}
}

static void	get_dist(t_raycast *rc)
{
	if (rc->side == 0)
		rc->perpwalldist = ft_abs((rc->map_x - rc->pos_x + (1 - rc->step_x) / 2)
			/ rc->raydir_x);
	else
		rc->perpwalldist = ft_abs((rc->map_y - rc->pos_y + (1 - rc->step_y) / 2)
			/ rc->raydir_y);
}

void	render_wolf(t_env *e)
{
	t_raycast	rc;
	int			x;

	x = 0;
	rc.pos_x = 22;
	rc.pos_y = 12;
	rc.dir_x = -1;
	rc.dir_y = 0;
	rc.plane_x = 0;
	rc.plane_y = 0.66;
	while (x < WIN_WIDTH)
	{
		ray_calculations(x, &rc);
		launch_ray(&rc, e);
		get_dist(&rc);
		draw_wall(x, &rc, e);
		x++;
	}

}
