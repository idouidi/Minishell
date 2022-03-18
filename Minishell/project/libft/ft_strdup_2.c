/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:35:25 by idouidi           #+#    #+#             */
/*   Updated: 2021/03/25 15:44:11 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_2(char **str)
{
	int		i;
	char	**newstr;

	i = 0;
	newstr = NULL;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	newstr = (char **)malloc(sizeof(char *) *(i + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = ft_strdup(str[i]);
		i++;
	}
	newstr[i] = NULL;
	return (newstr);
}
