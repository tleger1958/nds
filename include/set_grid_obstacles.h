/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid_obstacles.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:23:50 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 19:51:22 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_GRID_OBSTACLES_H
# define SET_GRID_OBSTACLES_H

# include <stdlib.h>

void	set_grid_number_obstacles(int ****grid_number_obstacles, char *map,
		char obstacle, int dimensions[2]);

void	set_first_line(int ****grid_number_obstacles, char *map,
		char obstacle, int dimensions[2]);

void	set_first_column(int ****grid_number_obstacles, char *map,
		char obstacle, int dimensions[2]);

void	set_grid_number(int x, int y, int c, int ****grid_number_obstacles);

void	truc_de_merde_car_la_norminette_c_de_la_merde(int *y, int *x);

#endif
