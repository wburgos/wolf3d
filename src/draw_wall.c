/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:21:20 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 06:43:06 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf.h"

void		draw_wall(int x, t_raycast *rc, t_env *e)
{
	int		y_start;
	int		y_end;
	int		color;
	int		line_height;
	int		map_val;

	map_val = e->map[rc->map_x][rc->map_y].val;
	line_height = ft_abs((int)(WIN_HEIGHT / rc->perpwalldist));
	y_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (y_start < 0)
		y_start = 0;
	y_end = line_height / 2 + WIN_HEIGHT / 2;
	if (y_end >= WIN_HEIGHT)
		y_end = WIN_HEIGHT - 1;
	if (rc->side == 1)
		map_val += 4;
	color = mlx_get_color_value(e->mlx, ft_hsvtorgb(map_val % 360, 100, 100));
	while (y_start < y_end)
		ft_putpix(e, x, y_start++, color);
}
