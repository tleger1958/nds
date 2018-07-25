/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thleger <thleger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 20:19:09 by thleger           #+#    #+#             */
/*   Updated: 2018/07/25 18:06:23 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft.h"

unsigned long long int	ft_strlen(char *str)
{
	unsigned long long int nb_characters;

	nb_characters = 0;
	while (str[nb_characters] != '\0')
	{
		nb_characters++;
	}
	return (nb_characters);
}
