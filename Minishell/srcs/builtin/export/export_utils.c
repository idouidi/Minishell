/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 14:48:19 by user42            #+#    #+#             */
/*   Updated: 2021/04/18 19:02:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*adjust_str_export5(char *s, char *tmp, int **i, int **stock)
{
	tmp[**stock] = s[**i];
	**stock += 1;
	return (tmp);
}

char	*adjust_str_export4(char *s, char *tmp, int *i, int *stock)
{
	if (s[*i] == 39 && ((*i == 0) || (*i - 1 >= 0 && s[*i - 1] != 92)))
	{
		*i += 1;
		while (s[*i] && s[*i] != 39)
		{
			tmp = adjust_str_export5(s, tmp, &i, &stock);
			*i += 1;
		}
	}
	else if (s[*i] == 34 && ((*i == 0) || (*i - 1 >= 0 && s[*i - 1] != 92)))
	{
		*i += 1;
		while (s[*i])
		{
			if (s[*i] == 34 && s[*i - 1] != 92)
				break ;
			tmp = adjust_str_export5(s, tmp, &i, &stock);
			*i += 1;
		}
	}
	else
		tmp = adjust_str_export5(s, tmp, &i, &stock);
	return (tmp);
}

char	*adjust_str_export3(char *s, char *tmp)
{
	int	i;
	int	stock;

	i = 0;
	stock = 0;
	while (s[i])
	{
		tmp = adjust_str_export4(s, tmp, &i, &stock);
		if (s[i])
			i++;
	}
	tmp[stock] = '\0';
	s = ft_leak(s);
	s = ft_strdup(tmp);
	tmp = ft_leak(tmp);
	return (s);
}

void	adjust_str_export2(char *s, int *i, int *stock)
{
	if ((*i == 0) || (*i - 1 >= 0 && s[*i - 1] != 92))
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
			while (s[*i])
			{
				if (s[*i] == 34 && s[*i - 1] != 92)
					break ;
				*i += 1;
			}
		}
		*stock += 2;
	}
}

char	*adjust_str_export(char *s)
{
	int		stock;
	int		i;
	char	*tmp;

	stock = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 39 || s[i] == 34)
			adjust_str_export2(s, &i, &stock);
		if (s[i])
			i++;
	}
	tmp = (char *)malloc(sizeof(char) * (i - stock + 1));
	if (tmp == NULL)
		return (NULL);
	s = adjust_str_export3(s, tmp);
	return (s);
}
