/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid_obstacles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:57:12 by thleger           #+#    #+#             */
/*   Updated: 2018/07/24 23:48:14 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/set_grid_obstacles.h"
#include "../include/utilities.h"

void 	set_grid_number_obstacles(int ****grid_number_obstacles, char *map,
		char obstacle, int dimensions[2])
{
	int x;
	int y;
	int i;
	int c;

	set_first_line(grid_number_obstacles, map, obstacle, dimensions);
	set_first_column(grid_number_obstacles, map, obstacle, dimensions);
	x = 1;
	y = 1;
	i = size_header(map) + 1 + dimensions[0] + 1;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			y++;
			x = 0;
			i++;
		}
		else
		{
			c = map[i] == obstacle ? 1 : 0;
			grid_number_obstacles[0][x][y] = malloc(sizeof(int));
			grid_number_obstacles[0][x][y][0] =
				grid_number_obstacles[0][x - 1][y][0] +
					grid_number_obstacles[0][x][y - 1][0] -
						grid_number_obstacles[0][x - 1][y - 1][0] + c;
		}
		x++;
		i++;
	}
}

void 	set_first_line(int ****grid_number_obstacles, char *map,
		char obstacle, int dimensions[2])
{
	int x;
	int c;
	int i;

	*grid_number_obstacles = malloc(sizeof(int **) * (dimensions[0] + 1));
	x = 0;
	c = 0;
	i = size_header(map);
	while (x < dimensions[0])
	{
		if (map[i] == obstacle)
			c++;
		grid_number_obstacles[0][x] = malloc(sizeof(int *) * dimensions[1]);
		grid_number_obstacles[0][x][0] = malloc(sizeof(int));
		grid_number_obstacles[0][x][0][0] = c;
		x++;
		i++;
	}
}

void 	set_first_column(int ****grid_number_obstacles, char *map,
		char obstacle, int dimensions[2])
{
	int y;
	int c;
	int i;

	y = 0;
	c = 0;
	i = size_header(map);
	while (y < dimensions[1])
	{
		if (map[i] == obstacle)
			c++;
		grid_number_obstacles[0][0][y] = malloc(sizeof(int));
		grid_number_obstacles[0][0][y][0] = c;
		y++;
		i += dimensions[0] + 1;
	}
}
