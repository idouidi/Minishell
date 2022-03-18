/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 03:54:34 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 19:19:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	quote_word(char *s, char **tab, int *j)
{
	int	i;

	i = 1;
	if (s[0] == 39)
		while (s[i] && s[i] != 39)
			i++;
	else
	{
		while (s[i])
		{
			if (s[i] == 34 && i - 1 >= 0 && s[i - 1] != 92)
				break ;
			i += 1;
		}
	}
	*tab = ft_substr(s, 0, i + 1);
	*j += 1;
	i += 1;
	return (i);
}

void	doll_word2(char *s, int *i)
{
	while (s[*i] && s[*i] != ' ' && s[*i] != ';' && s[*i] != '|'
		&& s[*i] != '\n' && s[*i] != '$' && s[*i] != 34 && s[*i] != 39)
	{
		if (s[*i] == 92 && s[*i - 1] != '$')
			break ;
		if (s[*i] == 92)
			*i += 2;
		else
			*i += 1;
	}
}

int	doll_word(char *s, char **tab, int	*j)
{
	int	i;

	i = 1;
	if (s[i] && s[i] == '?')
	{
		i += 1;
		*tab = ft_substr(s, 0, i);
		*j += 1;
		return (i);
	}
	else if (s[i] && !ft_isalnum(s[i]) && s[i] != '_')
		doll_word2(s, &i);
	else
		while (s[i] && (ft_isalnum(s[i]) || s[i] == '_'))
			i += 1;
	*tab = ft_substr(s, 0, i);
	*j += 1;
	return (i);
}

void	baic_word2(char *s, int *i, char ***tab)
{
	char	c[2];

	c[1] = 0;
	if (s[*i + 1] && ((s[*i] == '>' && s[*i + 1] == '>')
			|| (s[*i] == '<' && s[*i + 1] == '<')))
	{
		if (s[*i] == '>')
			**tab = ft_strdup(">>");
		else
			**tab = ft_strdup("<<");
		*i += 2;
	}
	else
	{
		c[0] = s[*i];
		**tab = ft_strdup(c);
		*i += 1;
	}
}

int	basic_word(char *s, char **tab, int *j)
{
	int	i;

	i = 0;
	if (s[i] == ';' || s[i] == '|' || s[i] == '<' || s[i] == '>')
		baic_word2(s, &i, &tab);
	else
	{
		while (s[i] && s[i] != 39 && s[i] != 34 && s[i] != ';' && s[i] != '|'
			&& s[i] != '$' && s[i] != '<' && s[i] != '>' && s[i] != '\n'
			&& s[i] != ' ')
		{
			if (s[i] == 92)
				i += 2;
			else
				i++;
		}
		*tab = ft_substr(s, 0, i);
	}
	*j += 1;
	return (i);
}
