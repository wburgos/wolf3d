/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:40:35 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 10:16:56 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "wolf.h"

static t_mapval	**map_push(t_mapval **map, t_mapval **new_map, t_mapval *line)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = line;
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}

static t_mapval	**add_to_map(t_mapval **map, t_mapval *line)
{
	t_mapval	**new_map;
	static int	len = 0;

	new_map = ft_memalloc(sizeof(t_mapval*) * (len + 2));
	if (new_map)
	{
		len++;
		if (map)
			new_map = map_push(map, new_map, line);
		else
		{
			new_map[0] = line;
			new_map[1] = NULL;
		}
	}
	return (new_map);
}

t_mapval		**read_map(char *file)
{
	int			fd;
	int			gnl;
	char		*line;
	t_mapval	**map;
	t_mapval	*splitted_line;

	map = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		die(file, 1);
	gnl = get_next_line(fd, &line);
	while (gnl != 0 && gnl != -1)
	{
		splitted_line = ft_nbrsplit(line);
		free(line);
		if (!splitted_line)
			break ;
		map = add_to_map(map, splitted_line);
		if (!map)
			break ;
		gnl = get_next_line(fd, &line);
	}
	if (gnl == -1 || !map || !splitted_line)
		die("Map parse error\n", 0);
	close(fd);
	return (map);
}
