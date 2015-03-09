/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 21:06:55 by wburgos           #+#    #+#             */
/*   Updated: 2015/03/09 23:16:32 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		die(char *err, int perr)
{
	if (perr)
		perror(err);
	else
		ft_putstr_fd(err, 2);
	exit (-1);
}
