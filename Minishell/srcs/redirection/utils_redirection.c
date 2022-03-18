/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:25:22 by user42            #+#    #+#             */
/*   Updated: 2021/07/02 14:31:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	arg_cancel_redir(char **s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (ft_strcmp(s[i], ">") == 0 || ft_strcmp(s[i], ">>") == 0
			|| ft_strcmp(s[i], "<") == 0 || ft_strcmp(s[i], "<<") == 0)
			i += 2;
		else
			return (i);
	}
	return (0);
}

int	count_arg(char **s, int *redir)
{
	int	i;
	int	arg;

	i = 0;
	arg = 0;
	while (s[i])
	{
		if (ft_strcmp(s[i], ">") == 0 || ft_strcmp(s[i], ">>") == 0
			|| ft_strcmp(s[i], "<") == 0 || ft_strcmp(s[i], "<<") == 0)
		{
			if (s[i + 1])
				i += 2;
			else
				i += 1;
			*redir = 1;
		}
		else
		{
			arg += 1;
			i += 1;
		}
	}
	return (arg);
}

char	**exec_expression_without_redir(char **s, char **expression)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (!ft_strcmp(s[i], ">") || !ft_strcmp(s[i], ">>")
			|| !ft_strcmp(s[i], "<") || !ft_strcmp(s[i], "<<"))
			i += 2;
		else
		{
			expression[j] = ft_strdup(s[i]);
			i += 1;
			j += 1;
		}
	}
	expression[j] = NULL;
	return (expression);
}

char	**expression_without_redir(char **s)
{
	char	**expression;
	int		count;
	int		redir;

	redir = 0;
	count = count_arg(s, &redir);
	if (count == 0)
	{
		if (redir == 1)
			s = ft_leak_2(s);
		return (s);
	}
	expression = malloc(sizeof(char *) * (count + 1));
	if (expression == NULL)
		return (NULL);
	expression = exec_expression_without_redir(s, expression);
	s = ft_leak_2(s);
	return (expression);
}
