/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:59:06 by user42            #+#    #+#             */
/*   Updated: 2021/04/13 14:39:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	showtab(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
	{
		printf("pointer is null\n");
		return ;
	}
	while (s[i])
	{
		while (s[i][j])
		{
			printf("[%c]", s[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}
