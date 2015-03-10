/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:54:01 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 03:43:22 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include "libft.h"

# define WIN_NAME 		"Wolf7d"
# define WIN_WIDTH 		1280
# define WIN_HEIGHT 	800
# define ESC_CODE		65307
# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364
# define KEYPRESS_MASK	(1L<<0)
# define KEYPRESS		2
# define BUFF_SIZE		128

typedef struct			s_mapval
{
	int		val;
	int		is_last;
}						t_mapval;

typedef struct			s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			size_line;
	int			bpp;
	char		*data;
	int			endian;
	t_mapval	**map;
}						t_env;

typedef struct			s_point
{
	int		x;
	int		y;
}						t_point;

typedef struct			s_line
{
	int		delta_x;
	int		delta_y;
	float	error;
	float	delta_error;
}						t_line;

typedef struct 			s_raycast
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	ttime;
	double	old_ttime;
	double	plane_x;
	double	plane_y;
	double	raydir_x;
	double	raydir_y;
	double	perpwalldist;
	double	raypos_x;
	double	raypos_y;
	int		camera_x;
	int		step_x;
	int		step_y;
	int		sidedist_x;
	int		sidedist_y;
	int		deltadist_x;
	int		deltadist_y;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
}						t_raycast;

int					get_next_line(int const fd, char **line);
int					die(char *err, int perr);
t_mapval			**read_map(char *file);
t_mapval			*ft_nbrsplit(char *str);
void				ft_putpix(t_env *e, int x, int y, int color);
void				ft_drawline(t_point p1, t_point p2, t_env *e, int color);
void				print_map(t_mapval **map); // Print de test, a virer
void				render_wolf(t_env *e);
void				draw_wall(int x, t_raycast *rc, t_env *e);

#endif
