/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:00:16 by user42            #+#    #+#             */
/*   Updated: 2021/12/01 18:00:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	there_is_pipe(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] && ft_strcmp(s[i], "|") == 0)
			return (1);
		i += 1;
	}
	return (0);
}

char	**cut_expression(char **s)
{
	char	**new;
	int		i;
	int		count;

	count = 0;
	i = 0;
	new = NULL;
	while (s[i] && ft_strcmp(s[i], "|") != 0)
	{
		count += 1;
		i += 1;
	}
	new = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (s[i] && ft_strcmp(s[i], "|") != 0)
	{
		new[i] = ft_strdup(s[i]);
		i += 1;
	}
	new[i] = NULL;
	return (new);
}

int	count_pipe(char **s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		count += 1;
		while (s[i] && ft_strcmp(s[i], "|") != 0)
			i += 1;
		if (s[i])
			i += 1;
	}
	return (count);
}

char	***split_each_cmd_btwn_pipe(char **s)
{
	int		i;
	int		j;
	int		count;
	char	***tab;

	count = count_pipe(s);
	i = 0;
	j = 0;
	tab = malloc(sizeof(char **) * (count + 1));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		tab[j] = cut_expression(&s[i]);
		while (s[i] && ft_strcmp(s[i], "|") != 0)
			i += 1;
		if (s[i])
			i += 1;
		j += 1;
	}
	tab[j] = NULL;
	return (tab);
}
