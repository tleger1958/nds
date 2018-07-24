/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:57:17 by thleger           #+#    #+#             */
/*   Updated: 2018/07/24 18:21:25 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

#include <stdlib.h>

void	handle_maps(char **maps);

void	solve(char *map, char obstacle);

void	set_result(int result[3], int ****grid_number_obstacles,
		int dimensions[2]);
		
#endif
