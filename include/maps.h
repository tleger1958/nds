/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:14:31 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 19:33:30 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include <stdlib.h>
# include <stdio.h>

void	set_maps(char ***maps, int argc, char **argv);

int		is_error(char *map);

int		body_error(char *map, char empty, char obstacle);

int		return_line(int *width, int *c, int *height);

#endif
