/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:29:50 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/09 19:07:33 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "wolf.h"

int		mlx_escape(int keycode, t_env *e)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == ESC_CODE)
		exit(0);
	return (0);
}

int		mlx_expose(t_env *e)
{
	ft_bzero((void *)(e->data), (WIN_HEIGHT * e->size_line) +
		(WIN_WIDTH + (e->bpp >> 3)));
	// Insert drawing algo
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line), &(e.endian));
	mlx_key_hook(e.win, mlx_escape, &e);
	mlx_expose_hook(e.win, mlx_expose, &e);
	mlx_loop(e.mlx);
	return (0);
}
