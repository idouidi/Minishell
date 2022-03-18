/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:34:23 by othabchi          #+#    #+#             */
/*   Updated: 2021/05/05 14:59:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, size_t len)
{
	size_t	i;
	size_t	stock;
	char	*newstr;

	i = 0;
	newstr = NULL;
	if (!s)
		return (NULL);
	if ((unsigned int)start > ft_strlen(s))
	{
		newstr[0] = '\0';
		return (newstr);
	}
	stock = len - start;
	newstr = (char *)malloc(sizeof(char) * (stock + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < stock && s[start])
	{
		newstr[i] = s[start++];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
