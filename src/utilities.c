/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:05:44 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 21:11:10 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utilities.h"
#include "../include/ft.h"

int		get_width(char *map)
{
	int i;
	int c;

	i = size_header(map);
	c = 0;
	while (map[i] != '\n')
	{
		c++;
		i++;
	}
	return (c);
}

int		get_height(char *map)
{
	int						i;
	int						j;
	char					*str_height;
	unsigned long long int	height;

	i = size_header(map) - 4;
	str_height = malloc((i + 1) * sizeof(char));
	j = 0;
	while (j < i)
	{
		str_height[j] = map[j];
		j++;
	}
	str_height[j] = '\0';
	height = ft_atoi(str_height);
	free(str_height);
	if (height > 2147483647)
		return (2147483647);
	else
		return ((int)height);
}

char	get_obstacle(char *map)
{
	return (map[size_header(map) - 3]);
}

int		size_header(char *map)
{
	int i;

	i = 0;
	while (map[i] != '\0' && map[i] != '\n')
		i++;
	if (map[i] == '\0')
		return (-1);
	else
		return (i + 1);
}

char	get_filled(char *map)
{
	return (map[size_header(map) - 2]);
}
