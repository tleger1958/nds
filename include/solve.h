/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:57:17 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 19:22:47 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

# include <stdlib.h>

void	handle_maps(char **maps);

void	solve(char *map, char obstacle, char filled);

void	set_solution(int result[3], int ****grid_number_obstacles,
		int dimensions[2]);

void	display_solution(char *map, int result[3], char filled);

int		is_fit(int x, int y, int s, int ****grid_number_obstacles);

#endif
