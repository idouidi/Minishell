/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:32:35 by othabchi          #+#    #+#             */
/*   Updated: 2021/04/28 18:25:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	newstr = NULL;
	newstr = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}
