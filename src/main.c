/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:14:21 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 19:21:48 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/maps.h"
#include "../include/stream.h"
#include "../include/ft.h"
#include "../include/solve.h"

int		main(int argc, char **argv)
{
	char	**maps;
	char	*av[2];

	av[0] = argv[0];
	av[1] = "temp/tmp.txt";
	if (argc == 1)
	{
		create_tmp();
		set_maps(&maps, 2, av);
	}
	else
		set_maps(&maps, argc, argv);
	handle_maps(maps);
	return (0);
}
