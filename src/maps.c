/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 16:20:23 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 19:42:39 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maps.h"
#include "../include/stream.h"
#include "../include/ft.h"
#include "../include/utilities.h"

void	set_maps(char ***maps, int argc, char **argv)
{
	int	i;

	*maps = malloc(argc * sizeof(char *));
	i = 1;
	while (i < argc)
	{
		if (number_char_file(argv[i]) == -1)
		{
			(*maps)[i - 1] = malloc(sizeof(char));
			(*maps)[i - 1][0] = '\0';
		}
		else
		{
			(*maps)[i - 1] = malloc((number_char_file(argv[i]) + 1) *
				sizeof(char));
			copy_file_to_str((*maps)[i - 1], argv[i]);
		}
		i++;
	}
	(*maps)[i - 1] = NULL;
}

int		is_error(char *map)
{
	int i;
	int j;

	if (*map == '\0' || size_header(map) == -1)
		return (1);
	i = size_header(map) - 4;
	j = 0;
	while (j < i)
	{
		if (map[j] < '0' || map[j] > '9')
			return (1);
		j++;
	}
	if (map[i] == map[i + 1] || map[i] == map[i + 2] ||
		map[i + 1] == map[i + 2])
		return (1);
	if (body_error(map, map[i], map[i + 1]) == 1)
		return (1);
	return (0);
}

int		body_error(char *map, char empty, char obstacle)
{
	int i;
	int c;
	int width;
	int height;

	height = 0;
	width = 0;
	i = size_header(map) - 1;
	c = 0;
	while (map[++i] != '\0')
	{
		if (map[i] == '\n')
		{
			if (return_line(&width, &c, &height) == 1)
				return (1);
		}
		else
		{
			if (map[i] != empty && map[i] != obstacle)
				return (1);
			c++;
		}
	}
	return (width == 0 || height != get_height(map) || map[i - 1] != '\n' ?
		1 : 0);
}

int		return_line(int *width, int *c, int *height)
{
	*width = *width == 0 ? *c : *width;
	if (*c != *width)
		return (1);
	*width = *c;
	*c = 0;
	(*height)++;
	return (0);
}
