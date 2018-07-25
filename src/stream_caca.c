/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_caca.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 21:30:45 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 21:34:24 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stream_caca.h"

void	caca_1(char chars[6], int i, int *return_line)
{
	chars[4] = chars[(i - 3) % 4];
	chars[5] = chars[(i - 2) % 4];
	*return_line = 1;
}

void	caca_2(char chars[6], int n, int *return_line)
{
	chars[4] = chars[(n - 3) % 4];
	chars[5] = chars[(n - 2) % 4];
	*return_line = 1;
}
