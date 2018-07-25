/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:14:40 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 19:24:37 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STREAM_H
# define STREAM_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

void	create_tmp(void);
void	copy_file_to_str(char *str, char *name_file);
int		number_char_file(char *name_file);

#endif
