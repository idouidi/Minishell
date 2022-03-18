/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:34:08 by othabchi          #+#    #+#             */
/*   Updated: 2021/04/09 22:59:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (n == 0)
		i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == n)
			return ((char *)str + i);
		i--;
	}
	if (i == -1)
		return ((char *) NULL);
	return (0);
}
