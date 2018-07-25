/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseguier <cseguier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 12:02:50 by cseguier          #+#    #+#             */
/*   Updated: 2018/07/25 19:21:08 by thleger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long int	ft_atoi(char *str)
{
	int						i;
	unsigned long long int	nb;
	int						sign;

	i = 0;
	nb = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	if (sign)
		return (-nb);
	return (nb);
}
