/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:29:37 by othabchi          #+#    #+#             */
/*   Updated: 2021/01/12 15:29:38 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*src;

	i = 0;
	dest = (unsigned char *)s;
	src = (unsigned const char *)s2;
	if (dest == src)
		return (0);
	while (i < (unsigned char)n)
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		else
			i++;
	}
	return (0);
}
