/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:44:18 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 10:09:06 by thomas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stream.h"

int		number_char_file(char *name_file)
{
	int		file;
	char	c;
	int		n;

	file = open(name_file, O_RDONLY);
	if (file == -1)
		return (0);
	n = 0;
	while (read(file, &c, 1))
		n++;
	close(file);
	return (n);
}

void 	copy_file_to_str(char *str, char *name_file)
{
	int		file;
	char	c;
	int		i;

	file = open(name_file, O_RDONLY);
	if (file == -1)
	{
		*str = '\0';
	}
	else
	{
		i = 0;
		while (read(file, &c, 1))
		{
			str[i] = c;
			i++;
		}
		str[i] = '\0';
		close(file);
	}
}

void 	read_input(void)
{
	char input;

	while (read(0, &input, 1) != 0)
		write (1, &input, 1);
}
