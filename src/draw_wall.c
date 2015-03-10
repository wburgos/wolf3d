/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:21:20 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 06:00:52 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_wall(int x, t_raycast *rc, t_env *e)
{
	int		y_start;
	int		y_end;
	int		color;
	int		line_height;

	line_height = ft_abs((int)(WIN_HEIGHT / rc->perpwalldist));
	y_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (y_start < 0)
		y_start = 0;
	y_end = line_height / 2 + WIN_HEIGHT / 2;
	if (y_end >= WIN_HEIGHT)
		y_end = WIN_HEIGHT - 1;
	switch(e->map[rc->map_x][rc->map_y].val)
      {
        case 1:  color = 0xFF0000;  break; //red
        case 2:  color = 0x00FF00;  break; //green
        case 3:  color = 0x0000FF;   break; //blue
        case 4:  color = 0xFFFFFF;  break; //white
        default: color = 0x00FFFF; break; //yellow
      }
	color = mlx_get_color_value(e->mlx, color);
	if (rc->side == 1)
		color /= 2;
	while (y_start < y_end)
		ft_putpix(e, x, y_start++, color);
}
