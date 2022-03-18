/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 22:05:48 by user42            #+#    #+#             */
/*   Updated: 2021/12/16 10:08:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(t_data *d, char **expression, int *redir)
{
	int	i;

	i = 0;
	while (*expression && (!ft_strcmp(*expression, "<")
			|| !ft_strcmp(*expression, "<<") || !ft_strcmp(*expression, ">")
			|| !ft_strcmp(*expression, ">>")))
	{
		*redir += 2;
		expression += 2;
	}
	if (!*expression)
		return (8);
	while (d->builtin_str[i])
	{
		if (!ft_strcmp(*expression, d->builtin_str[i]))
			break ;
		i++;
	}
	if (i == 7)
		return (-1);
	return (i);
}

int	builtin(t_data *d, char **expression)
{
	int	index;
	int	redir;

	redir = 0;
	index = is_builtin(d, expression, &redir);
	if (index != -1)
	{
		if (!d->sys_func)
		{
			if (redirection(d, expression) == -1)
			{
				update_return_cmd("?", "1", d);
				return (-2);
			}
		}
		if (redir)
			expression += redir;
		if (*expression)
			d->builtin_func[index](d, expression);
	}
	return (index);
}
