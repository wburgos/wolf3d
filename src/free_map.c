#include <stdlib.h>
#include "wolf.h"

void	free_map(t_mapval **map)
{
	int		i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}