/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:51:19 by idouidi           #+#    #+#             */
/*   Updated: 2021/07/07 15:55:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**pars_cmd(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && (!ft_strcmp(s[i], "\\;") || !ft_strcmp(s[i], "\\|")
				|| !ft_strcmp(s[i], "\\<") || !ft_strcmp(s[i], "\\>")
				|| !ft_strcmp(s[i], "\"\"")))
			i += 1;
		else
		{
			s[i] = adjust_str(s[i]);
			while (s[i] && ft_strcmp(s[i], ";") != 0
				&& ft_strcmp(s[i], "|") != 0)
				i++;
			if (s[i])
				i++;
		}
	}
	return (s);
}

char	**get_next_str(char *s, char **tab)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == 32 && s[i + 1] == '\n')
			i++;
		else if (s[i] == 32)
		{
			tab[j++] = ft_strdup(" ");
			while (s[i] == 32)
				i++;
		}
		else if ((s[i] == 39 || s[i] == 34)
			&& ((i - 1 >= 0 && s[i - 1] != 92) || i == 0))
			i += quote_word(&s[i], &tab[j], &j);
		else if (s[i] == '$')
			i += doll_word(&s[i], &tab[j], &j);
		else
			i += basic_word(&s[i], &tab[j], &j);
	}
	tab[j] = NULL;
	return (tab);
}

int	count_words(char *s)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == 39 || s[i] == 34)
			count_quote_word(s, &i, &word);
		else if (s[i] == '$')
			count_doll_word(s, &i, &word);
		else
			count_basic_word(s, &i, &word);
	}
	return (word);
}

char	**ft_split_minishell(t_data *d, char *s)
{
	char	**tab;
	int		word;

	tab = NULL;
	(void)d;
	word = count_words(s);
	if (word == 0)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (tab == NULL)
		return (NULL);
	tab = get_next_str(s, tab);
	tab = pars_cmd(tab);
	return (tab);
}
