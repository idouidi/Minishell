/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: othabchi <othabchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:33:58 by othabchi          #+#    #+#             */
/*   Updated: 2021/01/12 15:34:00 by othabchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	if (*needle == '\0')
		return ((char *)haystack);
	n = ft_strlen(needle);
	while (*haystack != '\0' && n <= len--)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, n) == 0)
			return ((char *)haystack);
		else
			haystack++;
	}
	return (NULL);
}
