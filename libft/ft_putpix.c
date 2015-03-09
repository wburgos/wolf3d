/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 14:59:29 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/09 18:57:22 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpix(t_env *e, int x, int y, int color)
{
	int		index;

	index = (y * e->size_line) + (x * (e->bpp >> 3));
	e->data[index] = color & 0xff;
	e->data[index + 1] = (color & 0xff00) >> 8;
	e->data[index + 2] = (color & 0xff0000) >> 16;
	e->data[index + 3] = 0;
}
