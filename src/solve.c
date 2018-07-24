/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:01:14 by thleger           #+#    #+#             */
/*   Updated: 2018/07/24 13:31:11 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solve.h"
#include "../include/utilities.h"
#include "../include/ft.h"
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
	int *grid_number_obstacles;

	set_obstacles_coordinates(&obstacles_coordinates, map, obstacle);
	set_grid_number_obstacles(&grid_number_obstacles, &obstacles_coordinates, map);

}

void 	set_grid_number_obstacles(int **grid_number_obstacles,
		int ***obstacles_coordinates, char *map)
{
	int x;
	int y;
	int width;
	int height;
	int i;
	int j;
	int c;

	width = get_width(map);
	height = get_height(map);
	*grid_number_obstacles = malloc(sizeof(int) * (width * height + 1));
	y = 0;
	i = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			j = 0;
			c = 0;
			while (obstacles_coordinates[0][j] != NULL)
			{
				if (x >= obstacles_coordinates[0][j][0] &&
					y >= obstacles_coordinates[0][j][1])
					c++;
				j++;
			}
			grid_number_obstacles[0][i] = c;
			x++;
			i++;
		}
		y++;
	}
	grid_number_obstacles[0][i] = -1;
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
