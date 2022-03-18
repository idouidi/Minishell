/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:18:29 by othabchi          #+#    #+#             */
/*   Updated: 2021/01/12 15:25:37 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*dest;

	dest = s;
	i = 0;
	while (i < (unsigned char)n)
	{
		dest[i] = 0;
		i++;
	}
}
