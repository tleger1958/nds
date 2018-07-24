/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:05:44 by thleger           #+#    #+#             */
/*   Updated: 2018/07/23 18:16:01 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utilities.h"

int 	get_width(char *map)
{
	int i;

	i = size_header(map);
	while (map[i] != '\n')
		i++;
	return (i);
}

int 	get_height(char *map)
{
	return (ft_atoi(map[0]));
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
