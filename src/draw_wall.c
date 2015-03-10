/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:21:20 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 03:41:43 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_wall(int x, t_raycast *rc, t_env *e)
{
	t_point	p1;
	t_point p2;
	int		color;
	int		line_height;

	p1.x = x;
	p2.x = x;
	line_height = ft_abs((int)(WIN_HEIGHT / rc->perpwalldist));
	p1.y = -line_height / 2 + WIN_HEIGHT / 2;
	if (p1.y < 0)
		p1.y = 0;
	p2.y = line_height / 2 + WIN_HEIGHT / 2;
	if (p2.y >= WIN_HEIGHT)
		p2.y = WIN_HEIGHT - 1;
	color = mlx_get_color_value(e->mlx, e->map[rc->map_x][rc->map_y].val * 255);
	if (rc->side == 1)
		color /= 2;
	ft_drawline(p1, p2, e, color);
}
