/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:14:21 by thleger           #+#    #+#             */
/*   Updated: 2018/07/23 18:09:42 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"
#include "../include/stream.h"
#include "../include/ft.h"
#include "../include/solve.h"

int main(int argc, char **argv)
{
	char **maps;

	if (argc == 1)
		read_input();
	set_maps(&maps, argc, argv);
	handle_maps(maps);
	return (0);
}
