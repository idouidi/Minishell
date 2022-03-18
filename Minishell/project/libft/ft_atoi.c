/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 15:49:45 by othabchi          #+#    #+#             */
/*   Updated: 2021/04/09 22:33:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12
		|| str[i] == 13 || str[i] == 11)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (res * neg);
		else
			res = (res * 10) + (long)(str[i] - '0');
		i++;
	}
	return (res * neg);
}
