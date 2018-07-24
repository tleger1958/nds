/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:05:44 by thleger           #+#    #+#             */
/*   Updated: 2018/07/24 19:07:29 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utilities.h"
#include "../include/ft.h"

int 	get_width(char *map)
{
	int i;
	int c;

	i = size_header(map);
	c = 0;
	while (map[i] != '\n')
	{
		c++;
		i++;
	}
	return (c);
}

int 	get_height(char *map)
{
	return (ft_atoi(&map[0]));
}

char	get_obstacle(char *map)
{
	return (map[2]);
}

int		size_header(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\n')
		i++;
	return (i + 1);
}

char 	get_plain(char *map)
{
	return (map[3]);
}
