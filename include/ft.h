/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:14:34 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 18:06:09 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

#include <unistd.h>
#include <stdlib.h>

void					ft_putchar(char c);
void					ft_putstr(char *str);
unsigned long long int	ft_strlen(char *str);
void					ft_destroy(char *str);
unsigned long long int	ft_atoi(char *str);

#endif
