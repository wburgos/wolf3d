/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:29:50 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 00:19:45 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>
#include "wolf.h"

static int	mlx_expose(t_env *e)
{
	ft_bzero((void *)(e->data), (WIN_HEIGHT * e->size_line) +
		(WIN_WIDTH + (e->bpp >> 3)));
	render_wolf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

static int	mlx_key(int keycode, t_env *e)
{
	(void)e;
	// printf("Key pressed: %d\n", keycode);
	if (keycode == ESC_CODE)
		exit(0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env		e;

	if (ac == 2)
	{
		e.map = read_map(av[1]);
		if (!(e.mlx = mlx_init()))
			die("Error initializing mlx\n", 0);
		e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
		e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT);
		e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line),
			&(e.endian));
		mlx_expose_hook(e.win, mlx_expose, &e);
		mlx_hook(e.win, KEYPRESS, KEYPRESS_MASK, mlx_key, &e);
		mlx_loop(e.mlx);
	}
	else
		die("Usage:\n./wolf3d map\n", 0);
	return (0);
}
