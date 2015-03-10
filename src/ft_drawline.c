/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:56:04 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 03:36:54 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	swap_points(t_point *p1, t_point *p2)
{
	float	tx;
	float	ty;

	tx = p1->x;
	ty = p1->y;
	if (tx > p2->x)
	{
		p1->x = p2->x;
		p1->y = p2->y;
		p2->x = tx;
		p2->y = ty;
	}
}

void		ft_drawline(t_point p1, t_point p2, t_env *e, int color)
{
	int		x;
	int		y;
	t_line	line;

	if (p1.x > p2.x)
		swap_points(&p1, &p2);
	x = p1.x;
	y = p1.y;
	line.delta_x = p2.x - p1.x;
	line.delta_y = p2.y - p1.y;
	line.error = 0;
	line.delta_error = ft_abs((float)line.delta_y / (float)line.delta_x);
	while (x < p2.x)
	{
		ft_putpix(e, x, y, color);
		line.error += line.delta_error;
		while (line.error >= 0.5)
		{
			ft_putpix(e, x, y, color);
			y += ft_sign(p2.y - p1.y);
			line.error -= 1;
		}
		x++;
	}
}
