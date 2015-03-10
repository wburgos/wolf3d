/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 03:21:20 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 11:04:20 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf.h"

static int	color_from_side(int side)
{
	if (side == 0)
		return (0x493829);
	if (side == 1)
		return (0x816C5B);
	if (side == 2)
		return (0xA9A18C);
	else
		return (0xB99C6B);
}

static void	draw_vertical_line(t_env *e, int x, t_verticalline line)
{
	int		i;

	i = 0;
	while (i++ < line.y_start)
		ft_putpix(e, x, i, 0x95D1FD);
	while (line.y_start < line.y_end)
		ft_putpix(e, x, line.y_start++, line.color);
	while (line.y_end < WIN_HEIGHT)
		ft_putpix(e, x, line.y_end++, 0x855723);
}

void		draw_wall(int x, t_raycast *rc, t_env *e)
{
	int				line_height;
	t_verticalline	line;

	line_height = ft_abs((int)(WIN_HEIGHT / rc->perpwalldist));
	if ((line.y_start = -line_height / 2 + WIN_HEIGHT / 2) < 0)
		line.y_start = 0;
	if ((line.y_end = line_height / 2 + WIN_HEIGHT / 2) >= WIN_HEIGHT)
		line.y_end = WIN_HEIGHT - 1;
	line.color = mlx_get_color_value(e->mlx, color_from_side(rc->side));
	draw_vertical_line(e, x, line);
}
