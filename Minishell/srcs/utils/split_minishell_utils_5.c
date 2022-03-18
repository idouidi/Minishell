/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell_utils_5.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 05:09:14 by user42            #+#    #+#             */
/*   Updated: 2021/06/02 16:30:48 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*adjust_str5(char *s, char *tmp, int **i, int **stock)
{
	if (s[**i] == '\a')
		tmp[**stock] = 92;
	else
		tmp[**stock] = s[**i];
	**stock += 1;
	return (tmp);
}

char	*adjust_str4(char *s, char *tmp, int *i, int *stock)
{
	if (s[*i] == 39 && (*i == 0 || (*i - 1 >= 0 && s[*i - 1] != 92)))
	{
		*i += 1;
		while (s[*i] && s[*i] != 39)
		{
			tmp = adjust_str5(s, tmp, &i, &stock);
			*i += 1;
		}
	}
	else if (s[*i] == 34 && (*i == 0 || (*i - 1 >= 0 && s[*i - 1] != 92)))
	{
		*i += 1;
		while (s[*i])
		{
			if (s[*i] == 34 && s[*i - 1] != 92)
				break ;
			if ((s[*i] == 92 && s[*i + 1] != '\a' && s[*i + 1] != '\"'
					&& s[*i + 1] != '$') || s[*i] != 92)
				tmp = adjust_str5(s, tmp, &i, &stock);
			*i += 1;
		}
	}
	else
		tmp = adjust_str5(s, tmp, &i, &stock);
	return (tmp);
}

char	*adjust_str3(char *s, char *tmp)
{
	int	i;
	int	stock;

	i = 0;
	stock = 0;
	while (s[i])
	{
		if (s[i] != 92)
			tmp = adjust_str4(s, tmp, &i, &stock);
		i++;
	}
	tmp[stock] = '\0';
	s = ft_leak(s);
	s = ft_strdup(tmp);
	tmp = ft_leak(tmp);
	return (s);
}

void	adjust_str2(char *s, int *i, int *remove)
{
	if (s[*i] == 39)
	{
		*i += 1;
		while (s[*i] && s[*i] != 39)
			*i += 1;
	}
	else if (s[*i] == 34)
	{
		*i += 1;
		while (s[*i] && s[*i] != 34)
		{
			if (s[*i] == 92 && (s[*i + 1] == '\a' || s[*i + 1] == '\"'
					|| s[*i + 1] == '$'))
			{
				*i += 2;
				*remove += 1;
			}
			else
				*i += 1;
		}
	}
	*remove += 2;
}

char	*adjust_str(char *s)
{
	int		remove;
	int		i;
	char	*tmp;

	remove = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 92)
			remove += 1;
		else if ((s[i] == 39 || s[i] == 34)
			&& (i == 0 || (i - 1 >= 0 && s[i - 1] != 92)))
			adjust_str2(s, &i, &remove);
		i++;
	}
	tmp = (char *)malloc(sizeof(char) * (i - remove + 1));
	if (tmp == NULL)
		return (NULL);
	s = adjust_str3(s, tmp);
	return (s);
}
