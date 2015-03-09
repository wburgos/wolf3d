/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 23:54:05 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/09 23:54:24 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf.h"

void		print_map(t_mapval **map)
{
	int		i = 0;
	int		j;

	while (map[i])
	{
		j = 0;
		while (!(map[i][j].is_last))
		{
			printf("%d ", map[i][j].val);
			j++;
		}
		printf("%d\n", map[i][j].val);
		i++;
	}
}
