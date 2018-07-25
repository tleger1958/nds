/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 18:08:48 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 19:23:29 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <stdlib.h>

int		get_width(char *map);
int		get_height(char *map);
char	get_obstacle(char *map);
int		size_header(char *map);
char	get_filled(char *map);

#endif
