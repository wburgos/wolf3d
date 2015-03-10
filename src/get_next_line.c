/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 14:19:18 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 06:23:55 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "wolf.h"

static char	*ft_strfjoin(char *s1, char *s2)
{
	char	*joined;

	joined = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (joined)
	{
		joined = ft_strcpy(joined, s1);
		joined = ft_strcat(joined, s2);
		free(s1);
	}
	return (joined);
}

static char	*parse_file(int fd)
{
	char	*buf;
	char	*file;
	int		bt;

	file = NULL;
	buf = malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((bt = read(fd, buf, BUFF_SIZE)))
	{
		if (bt == -1)
			return (NULL);
		buf[bt] = '\0';
		if (!file)
			file = ft_strdup(buf);
		else
			file = ft_strfjoin(file, buf);
		if (!file)
			return (NULL);
	}
	if (!file && bt == 0)
		file = ft_strdup("");
	free(buf);
	return (file);
}

int			get_next_line(int fd, char **line)
{
	static char		*file = NULL;
	static int		start = 0;
	int				end;

	if (start == 0)
		file = parse_file(fd);
	if (!file)
		return (-1);
	end = start;
	if (file[start] == '\0')
	{
		free(file);
		return (0);
	}
	while (file[end] != '\n' && file[end] != '\0')
		end++;
	*line = ft_strsub(file, start, (end - start));
	start = file[end] == '\0' ? end : end + 1;
	return (1);
}
