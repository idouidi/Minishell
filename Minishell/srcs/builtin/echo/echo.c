/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:07:46 by idouidi           #+#    #+#             */
/*   Updated: 2021/12/15 22:46:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	**pars_echo(char **s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		s[i] = adjust_str(s[i]);
		i++;
	}
	return (s);
}

void	exec_echo(t_data *d, char **s, int *i)
{
	int		space;
	char	*leak;

	space = 0;
	while (s[*i])
	{
		if (ft_strcmp(s[*i], ">") && ft_strcmp(s[*i], ">>")
			&& ft_strcmp(s[*i], "<") && ft_strcmp(s[*i], "<<"))
		{
			s[*i] = adjust_str(s[*i]);
			if (space != 0)
			{
				leak = d->redir;
				d->redir = ft_strjoin(d->redir, " ");
				leak = ft_leak(leak);
			}
			leak = d->redir;
			d->redir = ft_strjoin(d->redir, s[*i]);
			leak = ft_leak(leak);
			space = 1;
			*i += 1;
		}
		else
			*i += 2;
	}
}

int	is_option(char *s)
{
	int	i;

	i = 1;
	if (s[0] != '-')
		return (0);
	while (s[i])
	{
		if (s[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_echo(t_data *d, char **s)
{
	int		i;
	int		option;
	char	**cpy_s;

	i = 1;
	option = 0;
	cpy_s = ft_strdup_2(s);
	while (cpy_s[i])
	{
		cpy_s[i] = adjust_str(cpy_s[i]);
		if (!ft_strcmp(cpy_s[i], "-n") || is_option(cpy_s[i]))
			i++;
		else
			break ;
	}
	if (i != 1)
		option = 1;
	cpy_s = ft_leak_2(cpy_s);
	exec_echo(d, s, &i);
	ft_putstr_fd(d->redir, d->fd_stdout);
	if (option == 0)
		write(d->fd_stdout, "\n", 1);
	d->redir = ft_leak(d->redir);
	return (0);
}
