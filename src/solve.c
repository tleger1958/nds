/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:01:14 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 18:14:59 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solve.h"
#include "../include/utilities.h"
#include "../include/ft.h"
#include "../include/set_grid_obstacles.h"
#include "../include/maps.h"
#include <stdio.h>

void	handle_maps(char **maps)
{
	int i;

	i = 0;
	while (maps[i] != NULL)
	{
		if (is_error(maps[i]) == 1)
			ft_putstr("map error\n");
		else
			solve(maps[i], get_obstacle(maps[i]), get_filled(maps[i]));
		if (maps[i + 1] != NULL)
			ft_putchar('\n');
		i++;
	}
}

void	solve(char *map, char obstacle, char filled)
{
	int ***grid_number_obstacles;
	int dimensions_map[2];
	int result[3];

	dimensions_map[0] = get_width(map);
	dimensions_map[1] = get_height(map);
	set_grid_number_obstacles(&grid_number_obstacles, map, obstacle,
			dimensions_map);
	set_solution(result, &grid_number_obstacles, dimensions_map);
	display_solution(map, result, filled);
}

void	set_solution(int result[3], int ****grid_number_obstacles,
		int dimensions[2])
{
	int x;
	int y;
	int s;

	result[0] = -1;
	result[1] = -1;
	result[2] = 0;
	s = 1;
	y = -1;
	while (++y < dimensions[1])
	{
		x = -1;
		while (++x < dimensions[0])
		{
			while (x + s <= dimensions[0] && y + s <= dimensions[1] &&
				is_fit(x, y, s, grid_number_obstacles) == 1)
			{
				result[0] = x;
				result[1] = y;
				result[2] = s;
				s++;
			}
		}
	}
}

int		is_fit(int x, int y, int s, int ****grid_number_obstacles)
{
	int tl;
	int bl;
	int tr;
	int br;

	x -= 1;
	y -= 1;
	tl = x == -1 || y == -1 ? 0 : grid_number_obstacles[0][x][y][0];
	bl = x == -1 ? 0 : grid_number_obstacles[0][x][y + s][0];
	tr = y == -1 ? 0 : grid_number_obstacles[0][x + s][y][0];
	br = grid_number_obstacles[0][x + s][y + s][0];
	if (br - bl - tr + tl > 0)
		return (0);
	return (1);
}

void	display_solution(char *map, int result[3], char filled)
{
	int i;
	int x;
	int y;

	i = size_header(map) - 1;
	x = 0;
	y = 0;
	while (map[++i] != '\0')
	{
		if (map[i] == '\n')
		{
			y++;
			x = 0;
			ft_putchar(map[i]);
		}
		else
		{
			if (x >= result[0] && x < result[0] + result[2] &&
				y >= result[1] && y < result[1] + result[2])
				ft_putchar(filled);
			else
				ft_putchar(map[i]);
			x++;
		}
	}
}
