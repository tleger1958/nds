/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:01:14 by thleger           #+#    #+#             */
/*   Updated: 2018/07/24 18:22:19 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solve.h"
#include "../include/utilities.h"
#include "../include/ft.h"
#include "../include/set_grid_obstacles.h"
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
	int ***grid_number_obstacles;
	int dimensions_map[2];
	int result[3];

	dimensions_map[0] = get_width(map);
	dimensions_map[1] = get_height(map);
	set_grid_number_obstacles(&grid_number_obstacles, map, obstacle,
			dimensions_map);
	printf("%s\n", map);
	int x, y = 0;
	while (y < dimensions_map[1])
	{
		x = 0;
		while (x < dimensions_map[0])
		{
			printf("%i", grid_number_obstacles[x][y][0]);
			x++;
		}
		y++;
		printf("%s\n", "");
	}
	set_result(result, &grid_number_obstacles, dimensions_map);
	printf("result: x=%i, y=%i, s=%i\n", result[0], result[1], result[2]);
}

void	set_result(int result[3], int ****grid_number_obstacles,
		int dimensions[2])
{
	int x;
	int y;
	int s;

	result[0] = 0;
	result[1] = 0;
	result[2] = 1;
	s = 1;
	y = 0;
	while (y < dimensions[1])
	{
		x = 0;
		while (x < dimensions[0])
		{
			while (grid_number_obstacles[0][result[0] + result[2]]
				[result[1] + result[2]][0] - grid_number_obstacles[0]
					[result[0]][result[1] + result[2]][0] -
						grid_number_obstacles[0][result[0] + result[2]]
							[result[1]][0] + grid_number_obstacles[0][result[0]]
								[result[1]][0] <= 0)
			{
				result[0] = x;
				result[1] = y;
				result[2] = s;
				s++;
			}
			x++;
		}
		y++;
	}
}
