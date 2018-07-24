/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:01:14 by thleger           #+#    #+#             */
/*   Updated: 2018/07/23 18:24:42 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solve.h"
#include "../include/utilities.h"
#include <stdio.h>

void	handle_maps(char **maps)
{
	int i;

	i = 0;
	while (maps[i] != NULL)
	{
		/*if (is_error(maps[i]) == 1)
			ft_pustr("map_error\n");
		else
			solve(maps[i]);*/
		solve(maps[i], get_obstacle(maps[i]));
		i++;
	}
}

void	solve(char *map, char obstacle)
{
	int **obstacles_coordinates;
	int x;
	int y;
	int width;
	int height;
	int s;
	int	square[2];
	int point[2];

	set_obstacles_coordinates(&obstacles_coordinates, map, obstacle);
	width = get_width(map);
	height = get_height(map);
	square[0] = 0;
	square[1] = 0;
	point[0] = 0;
	point[1] = 0;
	s = 0;
	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			while (is_correct(point, square))
			{
				s++;
				set_square(point, square, s);
			}
			s = 0;
			y++;
		}
		x++;
	}
}

int 	is_correct(int point[2], int square[2])
{
	
}

void 	set_obstacles_coordinates(int ***obstacles_coordinates, char *map,
		char obstacle)
{
	int i;
	int x;
	int y;
	int c;

	*obstacles_coordinates = malloc(sizeof(int *) * (
		number_obstacles(map, obstacle) + 1));
	i = size_header(map);
	y = 0;
	x = 0;
	c = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			x = 0;
			y++;
		}
		else
		{
			if (map[i] == obstacle)
			{
				(*obstacles_coordinates)[c] = malloc(2 * sizeof(int));
				(*obstacles_coordinates)[c][0] = x;
				(*obstacles_coordinates)[c][1] = y;
				c++;
			}
			x++;
		}
		i++;
	}
	(*obstacles_coordinates)[c] = NULL;
}

int 	number_obstacles(char *map, char obstacle)
{
	int c;
	int i;

	c = 0;
	i = size_header(map);
	while (map[i] != '\0')
	{
		if (map[i] == obstacle)
			c++;
		i++;
	}
	return (c);
}
