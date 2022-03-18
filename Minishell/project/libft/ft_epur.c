/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:26:32 by othabchi          #+#    #+#             */
/*   Updated: 2021/04/09 22:30:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*count_word_n_length(char *s, int *tab)
{
	int	i;
	int	word;
	int	length;

	i = 0;
	word = 0;
	length = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
		{
			word++;
			while (s[i] && s[i] != ' ' && s[i] != '\t')
			{
				length++;
				i++;
			}
		}
		if (s[i])
			i++;
	}
	tab[0] = word;
	tab[1] = length;
	return (tab);
}

static char	*fill_str(char *tmp, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] != ' ' && s[i] != '\t')
		{
			while (s[i] && s[i] != ' ' && s[i] != '\t')
			{
				tmp[j] = s[i];
				i++;
				j++;
			}
			tmp[j] = ' ';
			j++;
		}
		if (s[i])
			i++;
	}
	tmp[j - 1] = '\0';
	return (tmp);
}

char	*ft_epur(char *s)
{
	char	*tmp;
	int		count;
	int		tab[2];

	tmp = NULL;
	count_word_n_length(s, tab);
	count = (tab[0] - 1) + tab[1];
	tmp = malloc(sizeof(char) * (count + 1));
	if (tmp == NULL)
		return (NULL);
	tmp = fill_str(tmp, s);
	free(s);
	return (tmp);
}
