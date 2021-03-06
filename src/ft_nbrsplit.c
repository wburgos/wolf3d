/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:18:46 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/10 09:39:01 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "wolf.h"

static t_mapval	*push_val(t_mapval *mapval, t_mapval *new_mapval, char *nbr)
{
	int		i;

	i = 0;
	while (!mapval[i].is_last)
	{
		new_mapval[i].val = mapval[i].val;
		new_mapval[i].is_last = mapval[i].is_last;
		i++;
	}
	new_mapval[i].val = mapval[i].val;
	new_mapval[i].is_last = 0;
	new_mapval[i + 1].val = ft_atoi(nbr);
	new_mapval[i + 1].is_last = 1;
	free(mapval);
	return (new_mapval);
}

static t_mapval	*add_val(t_mapval *mapval, char *nbr)
{
	t_mapval	*new_mapval;
	static int	len = 0;

	new_mapval = ft_memalloc(sizeof(t_mapval) * (len + 1));
	if (new_mapval)
	{
		len++;
		if (mapval)
			push_val(mapval, new_mapval, nbr);
		else
		{
			new_mapval[0].is_last = 1;
			new_mapval[0].val = ft_atoi(nbr);
		}
	}
	return (new_mapval);
}

t_mapval		*ft_nbrsplit(char *str)
{
	int			i;
	int			j;
	t_mapval	*mapval;

	i = 0;
	mapval = NULL;
	while (str && str[i] != '\0')
	{
		while (str[i] != '\0' && !ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0')
			break ;
		j = i;
		while (ft_isdigit(str[j]))
			j++;
		mapval = add_val(mapval, ft_strsub(str, i, j - i));
		i = j;
	}
	return (mapval);
}
