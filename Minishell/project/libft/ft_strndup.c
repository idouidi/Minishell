/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:33:29 by othabchi          #+#    #+#             */
/*   Updated: 2021/04/09 23:03:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*newstr;

	i = 0;
	if (n > ft_strlen(str))
		n = ft_strlen(str);
	newstr = (char *)malloc(sizeof(char) *(n + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < n)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
