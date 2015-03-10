/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 07:19:57 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 07:20:34 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

void	ft_rotate(double *dir_x, double *dir_y, double angle)
{
	double	tmp;

	tmp = *dir_x;
	*dir_x = *dir_x * cos(angle) - *dir_y * sin(angle);
	*dir_y = tmp * sin(angle) + *dir_y * cos(angle);
}
