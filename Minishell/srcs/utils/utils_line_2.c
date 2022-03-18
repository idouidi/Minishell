/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 20:21:47 by user42            #+#    #+#             */
/*   Updated: 2021/12/15 21:22:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*transform_slash(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == 92 && s[i + 1] == 92)
			s[i + 1] = '\a';
		i++;
	}
	return (s);
}

int	error_redir(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i += 1;
	if (s[i] == 0 || s[i] == '\n' || s[i] == ';' || s[i] == '|'
		|| s[i] == '<' || s[i] == '>')
		return (-1);
	return (0);
}

int	check_line(t_data *d)
{
	int	error;

	error = check_quote_sep_redir(d->line);
	if (error != 0)
	{
		if (error == -1)
			ft_putstr_fd("multi line is not checked\n", 2);
		else
			ft_putstr_fd("syntax error near unexpected token\n", 2);
		update_return_cmd("?", "258", d);
	}
	return (error);
}

char	**real_split(char **s, t_data *d)
{
	int		i;
	int		remove;
	char	**tab;

	i = 0;
	remove = 0;
	while (s[i])
	{
		if (s[i][0] == '$' && s[i][1] != 92 && ft_strcmp(s[i], "$") != 0)
			s[i] = change_env_var(d, s[i]);
		else if (s[i][0] == 34 && ft_strchr(s[i], '$'))
			s[i] = change_doll_in_double_quote(s[i], d);
		else if (ft_strcmp(s[i], " ") == 0 || ft_strcmp(s[i], "") == 0)
			remove += 1;
		i += 1;
	}
	tab = malloc(sizeof(char *) * (i - remove + 1));
	if (tab == NULL)
		return (NULL);
	tab = real_split2(s, tab);
	s = ft_leak_2(s);
	return (tab);
}

char	**split_expression(char **s, t_data *d)
{
	char	**tmp;
	int		i;

	i = 0;
	while (s[i] && ft_strcmp(s[i], ";") != 0)
		i += 1;
	tmp = malloc(sizeof(char *) * (i + 1));
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (s[i] && ft_strcmp(s[i], ";") != 0)
	{
		tmp[i] = ft_strdup(s[i]);
		i += 1;
	}
	tmp[i] = NULL;
	tmp = real_split(tmp, d);
	return (tmp);
}
