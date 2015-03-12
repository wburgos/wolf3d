/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:29:50 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 11:12:44 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf.h"

static int	mlx_expose(t_env *e)
{
	ft_bzero((void *)(e->data), (WIN_HEIGHT * e->size_line) +
		(WIN_WIDTH + (e->bpp >> 3)));
	render_wolf(e, &(e->rc));
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

static int	mlx_key(int keycode, t_env *e)
{
	if (keycode == ESC_CODE)
	{
		mlx_destroy_image(e->mlx, e->img);
		free_map(e->map);
		exit(0);
	}
	if (keycode == CROUCH || keycode == WALK)
	{
		e->rc.slow = 1;
		if (keycode == CROUCH)
			e->rc.crouch = 1;
		mlx_expose(e);
	}
	if ((keycode >= LEFT && keycode <= DOWN)
		|| keycode == W || keycode == A || keycode == S || keycode == D)
	{
		move(e->map, &(e->rc), keycode);
		mlx_expose(e);
	}
	return (0);
}

static int	mlx_relkey(int keycode, t_env *e)
{
	if (keycode == CROUCH || keycode == WALK)
	{
		e->rc.slow = 0;
		if (keycode == CROUCH)
			e->rc.crouch = 0;
		mlx_expose(e);
	}
	return (0);
}

static void init_rc(t_raycast *rc)
{
	rc->pos_x = 3;
	rc->pos_y = 18;
	rc->dir_x = -1;
	rc->dir_y = 0;
	rc->plane_x = 0;
	rc->plane_y = 0.66;
	rc->crouch = 0;
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
		e.map = read_map(av[1]);
	else
		e.map = read_map("map");
	if (!(e.mlx = mlx_init()))
		die("Error initializing mlx\n", 0);
	if (!(e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME)))
		die("Error initializing window\n", 0);
	if (!(e.img = mlx_new_image(e.mlx, WIN_WIDTH, WIN_HEIGHT)))
		die("Error initializing image\n", 0);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line),
		&(e.endian));
	init_rc(&(e.rc));
	mlx_expose_hook(e.win, mlx_expose, &e);
	mlx_hook(e.win, KEYPRESS, KEYPRESS_MASK, mlx_key, &e);
	mlx_hook(e.win, KEYREL, KEYREL_MASK, mlx_relkey, &e);
	mlx_loop(e.mlx);
	return (0);
}
