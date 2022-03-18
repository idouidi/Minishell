/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:29:00 by othabchi          #+#    #+#             */
/*   Updated: 2021/04/09 22:46:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memalloc(size_t n)
{
	void	*mem;

	mem = malloc(sizeof(n));
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, n);
	return (mem);
}
