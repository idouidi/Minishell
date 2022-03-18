/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 11:32:30 by idouidi           #+#    #+#             */
/*   Updated: 2021/12/01 18:00:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_sep(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == 32)
			i++;
		if (s[i] == ';' || s[i] == '|')
			return (-2);
		while (s[i] && (s[i] != ';' && s[i] != '|'))
			i++;
		if (s[i] == '|' && s[i + 1] == '\n')
			return (-1);
		if (s[i])
			i++;
	}
	return (0);
}

int	check_redir2(char *s, int **i)
{
	**i += 1;
	if (s[**i] != '<')
	{
		if (error_redir(&s[**i]) == -1)
			return (-1);
	}
	else
	{
		**i += 1;
		if (error_redir(&s[**i]) == -1)
			return (-1);
	}
	return (0);
}

int	check_redir(char *s, int *i)
{
	if (s[*i] == '>')
	{
		*i += 1;
		if (s[*i] != '>')
		{
			if (error_redir(&s[*i]) == -1)
				return (-1);
		}
		else
		{
			*i += 1;
			if (error_redir(&s[*i]) == -1)
				return (-1);
		}
	}
	else if (check_redir2(s, &i) == -1)
		return (-1);
	return (0);
}

int	check_quote(char *s, int *i)
{
	if (s[*i] == 39)
	{
		*i += 1;
		while (s[*i] && s[*i] != 39)
			*i += 1;
		if (s[*i] != 39)
			return (-1);
	}
	else if (s[*i] == 34)
	{
		*i += 1;
		while (s[*i])
		{
			if (s[*i] == 34 && *i - 1 >= 0 && s[*i - 1] != 92)
				break ;
			*i += 1;
		}
		if (s[*i] != 34)
			return (-1);
	}
	return (0);
}

int	check_quote_sep_redir(char *s)
{
	int	i;

	s = transform_slash(s);
	i = 0;
	while (s[i])
	{
		if (s[i] == 92 && s[i + 1] == 0)
			return (-1);
		if (s[i] == 92)
			i += 2;
		else
		{
			if (s[i] == 39 || s[i] == 34)
			{
				if (check_quote(s, &i) == -1)
					return (-1);
			}
			else if (s[i] == '>' || s[i] == '<')
				if (check_redir(s, &i) == -1)
					return (-2);
			i += 1;
		}
	}
	i = check_sep(s);
	return (i);
}
