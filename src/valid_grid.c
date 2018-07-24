/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:28:21 by cseguier          #+#    #+#             */
/*   Updated: 2018/07/23 18:48:33 by cseguier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../include/bsq.h"
#include "../include/ft.h"
#include "../include/map_error.h"
#include "../include/stream.h"

int	is_error(char *grid)
{
	int		i;
	int		j;
	int		nb[3];
	char	param[3];

	i = -1;
	*nb = 0;
	while (grid[++i])
	{
		if (!(grid[0] >= '0' && grid[0] <= '9'))
			return (1);
		while (nb[0] == 0 && grid[i] >= '0' && grid[i] <= '9')
		{
			nb[1] *= 10;
			nb[1] += (int)grid[i++] - '0';
		}
		nb[0]++;
		param[0] = grid[i++];
		param[1] = grid[i++];
		param[2] = grid[i++];
		if (grid[i++] != '\n')
			return (1);
		nb[3] = 0;
		//maj variable necessaire, confondu hauteur et largeur
		while (nb[3] > j && grid[i] != '\n' && (grid[i] == param[0]
			|| grid[i] == param[1] || grid[i] == param[2]))
		{
			j++;
			i++;
		}
		if (j != nb[1] || grid[i] != '\n')
			return (1);
	}
	return (0);
}
