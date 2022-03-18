/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell_utils_4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 05:06:54 by user42            #+#    #+#             */
/*   Updated: 2021/06/04 03:34:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*change_doll_in_double_quote5(char *tmp, char *tmp2, int *j)
{
	int	i;

	i = 0;
	while (tmp2[i])
	{
		tmp[*j] = tmp2[i];
		i += 1;
		*j += 1;
	}
	return (tmp);
}

char	*change_doll_in_double_quote4(char *s, int *i, t_data *d)
{
	char	*tmp2;
	int		j;
	int		i_cpy;

	i_cpy = *i;
	j = i_cpy + 1;
	if (s[j] != '?')
	{
		while (s[j] && (ft_isalnum(s[j]) || s[j] == '_'))
			j += 1;
		tmp2 = ft_substr(s, i_cpy, j);
	}
	else
	{
		tmp2 = ft_strdup("$?");
		j += 1;
	}
	tmp2 = change_env_var(d, tmp2);
	*i = j;
	return (tmp2);
}

char	*change_doll_in_double_quote3(char *s, char *tmp, t_data *d)
{
	char		*tmp2;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i - 1] != 92
			&& (ft_isalnum(s[i + 1]) || s[i + 1] == '_' || s[i + 1] == '?'))
		{
			tmp2 = change_doll_in_double_quote4(s, &i, d);
			tmp = change_doll_in_double_quote5(tmp, tmp2, &j);
			tmp2 = ft_leak(tmp2);
		}
		else
		{
			tmp[j] = s[i];
			i += 1;
			j += 1;
		}
	}
	tmp[j] = '\0';
	return (tmp);
}

void	change_doll_in_double_quote2(char *s, int *i, int *count, t_data *d)
{
	char	*tmp;
	int		i_cpy;
	int		j;

	tmp = NULL;
	i_cpy = *i;
	j = *i + 1;
	if (s[j] != '?')
	{
		while (s[j] && (ft_isalnum(s[j]) || s[j] == '_'))
			j += 1;
		tmp = ft_substr(s, i_cpy, j);
	}
	else
	{
		tmp = ft_strdup("$?");
		j += 1;
	}
	tmp = change_env_var(d, tmp);
	if (ft_strcmp(tmp, "") != 0)
		*count += ft_strlen(tmp);
	tmp = ft_leak(tmp);
	*i = j;
}

char	*change_doll_in_double_quote(char *s, t_data *d)
{
	int		i;
	int		count;
	char	*tmp;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i - 1] != 92
			&& (ft_isalnum(s[i + 1]) || s[i + 1] == '_' || s[i + 1] == '?'))
			change_doll_in_double_quote2(s, &i, &count, d);
		else
		{
			count += 1;
			i += 1;
		}
	}
	tmp = malloc(sizeof(char) * (count + 1));
	if (tmp == NULL)
		return (NULL);
	tmp = change_doll_in_double_quote3(s, tmp, d);
	s = ft_leak(s);
	s = ft_strdup(tmp);
	tmp = ft_leak(tmp);
	return (s);
}
