#include "wolf.h"

char	*change_map(int keycode, char *map_name)
{
	ft_strncpy(map_name, "maps/", 5);
	map_name[5] = (char)keycode;
	ft_strcat(map_name, ".map");
	printf("%s\n", map_name);
	return (map_name);
}