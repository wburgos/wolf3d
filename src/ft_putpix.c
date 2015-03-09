/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:12:37 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/09 23:40:41 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_putpix(t_env *e, int x, int y, int color)
{
	int		index;
	int		color_value;

	color_value = mlx_get_color_value(e->mlx, color);
	index = (y * e->size_line) + (x * (e->bpp >> 3));
	e->data[index] = color_value & 0xff;
	e->data[index + 1] = (color_value & 0xff00) >> 8;
	e->data[index + 2] = (color_value & 0xff0000) >> 16;
	e->data[index + 3] = 0;
}
