/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell_utils_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:32:58 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/02 12:21:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	str_only_quote(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 39 && s[i] != 34)
			return (1);
		i += 1;
	}
	return (0);
}

char	**real_split4(char **s, int *i, int *j, char **tab)
{
	char	*tmp;
	char	*leak;

	tmp = ft_strdup("");
	while (s[*i] && ft_strcmp(s[*i], " ") != 0 && ft_strcmp(s[*i], ";") != 0
		&& ft_strcmp(s[*i], "|") != 0 && ft_strcmp(s[*i], "$") != 0
		&& ft_strcmp(s[*i], ">") != 0 && ft_strcmp(s[*i], ">>") != 0
		&& ft_strcmp(s[*i], "<") != 0 && ft_strcmp(s[*i], "<<") != 0)
	{
		leak = tmp;
		tmp = ft_strjoin(tmp, s[*i]);
		leak = ft_leak(leak);
		*i += 1;
	}
	tab[*j] = ft_strdup(tmp);
	tmp = ft_leak(tmp);
	return (tab);
}

char	**real_split3(char **s, int *i, int *j, char **tab)
{
	tab[*j] = ft_strdup(s[*i]);
	*j += 1;
	*i += 1;
	return (tab);
}

int	is_present(char *s, int case_)
{
	if (case_ == 0 && (!ft_strcmp(s, ";") || !ft_strcmp(s, "|")
			|| !ft_strcmp(s, "$") || !ft_strcmp(s, ">") || !ft_strcmp(s, ">>")
			|| !ft_strcmp(s, "<") || !ft_strcmp(s, "<<")))
		return (1);
	else if (case_ == 1 && (!ft_strcmp(s, " ") || !ft_strcmp(s, ";")
			|| !ft_strcmp(s, "|") || !ft_strcmp(s, "$") || !ft_strcmp(s, ">")
			|| !ft_strcmp(s, ">>") || !ft_strcmp(s, "<")
			|| !ft_strcmp(s, "<<")))
		return (1);
	return (0);
}

char	**real_split2(char **s, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (ft_strcmp(s[i], " ") == 0 || ft_strcmp(s[i], "") == 0)
			i++;
		else if (is_present(s[i], 0) || (s[i + 1] && !ft_strcmp(s[i], "")
				&& is_present(s[i + 1], 1)))
			tab = real_split3(s, &i, &j, tab);
		else
		{
			tab = real_split4(s, &i, &j, tab);
			if (str_only_quote(tab[j]) == 0)
			{
				tab[j] = ft_leak(tab[j]);
				tab[j] = ft_strdup("");
			}
			j += 1;
		}
	}
	tab[j] = NULL;
	return (tab);
}
