/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 13:34:40 by idouidi           #+#    #+#             */
/*   Updated: 2021/06/02 16:30:29 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	count_quote_word(char *s, int *i, int *word)
{
	*i += 1;
	*word += 1;
	if (s[*i - 1] == 39)
		while (s[*i] && s[*i] != 39)
			*i += 1;
	else if (s[*i - 1] == 34)
	{
		while (s[*i] && s[*i] != 34)
		{
			if (s[*i] == 92)
				*i += 2;
			else
				*i += 1;
		}
	}
	*i += 1;
}

void	count_doll_word(char *s, int *i, int *word)
{
	*word += 1;
	*i += 1;
	if (s[*i] && !ft_isalnum(s[*i]) && s[*i] != '_' && s[*i] != '?')
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
	else
		while (s[*i] && (ft_isalnum(s[*i]) || s[*i] == '_'))
			*i += 1;
	if (s[*i] && s[*i] == '?')
		*i += 1;
}

void	count_basic_word(char *s, int *i, int *word)
{
	if (s[*i] == ';' || s[*i] == '|' || s[*i] == '<' || s[*i] == '>'
		|| (s[*i] == ' ' && s[*i + 1] != ' ' && s[*i + 1] != '\n'))
	{
		*word += 1;
		*i += 1;
	}
	else if (s[*i] != ';' && s[*i] != '|' && s[*i] != '\n' && s[*i] != ' ')
	{
		while (s[*i] && s[*i] != 39 && s[*i] != 34 && s[*i] != ';'
			&& s[*i] != '|' && s[*i] != '$' && s[*i] != '>' && s[*i] != '<'
			&& s[*i] != '\n' && s[*i] != ' ')
		{
			if (s[*i] == 92)
				*i += 2;
			else
				*i += 1;
		}
		*word += 1;
	}
	else
		*i += 1;
}
