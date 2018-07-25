/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:44:18 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 21:34:29 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/stream.h"
#include "../include/stream_caca.h"

int		number_char_file(char *name_file)
{
	int		file;
	char	c;
	char	chars[6];
	int		return_line;
	int		n;

	file = open(name_file, O_RDONLY);
	if (file == -1)
		return (-1);
	n = 0;
	return_line = 0;
	while (read(file, &c, 1))
	{
		chars[n % 4] = c;
		if (c == '\n' && return_line == 0)
			caca_2(chars, n, &return_line);
		if (return_line == 1 && c != '\n' && c != chars[4] && c != chars[5])
			return (-1);
		n++;
	}
	close(file);
	return (n);
}

void	copy_file_to_str(char *str, char *name_file)
{
	int		file;
	char	c;
	int		i;

	file = open(name_file, O_RDONLY);
	i = 0;
	while (read(file, &c, 1))
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	close(file);
}

void	create_tmp(void)
{
	int		file;
	char	chars[6];
	int		return_line;
	int		i;
	char	c;

	return_line = 0;
	i = 0;
	file = open("temp/tmp.txt", O_WRONLY | O_TRUNC);
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		chars[i % 4] = c;
		if (c == '\n' && return_line == 0)
			caca_1(chars, i, &return_line);
		if (return_line == 1 && c != '\n' && c != chars[4] && c != chars[5])
		{
			write(file, &c, 1);
			break ;
		}
		write(file, &c, 1);
		i++;
	}
	close(file);
}
