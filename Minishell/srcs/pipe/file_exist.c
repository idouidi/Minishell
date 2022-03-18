/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:30:29 by user42            #+#    #+#             */
/*   Updated: 2021/12/15 21:40:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*join_path_cmd(char *path, char *slash, char *cmd)
{
	char	*leak;
	char	*tmp;

	tmp = ft_strjoin(path, slash);
	leak = tmp;
	tmp = ft_strjoin(tmp, cmd);
	leak = ft_leak(leak);
	cmd = ft_leak(cmd);
	cmd = ft_strdup(tmp);
	tmp = ft_leak(tmp);
	return (cmd);
}

int	loop_check_if_file_exist(t_data *d, char *tab, int i)
{
	while (d->entry)
	{
		if (ft_strcmp(d->pipe[i][0], d->entry->d_name) == 0)
		{
			d->pipe[i][0] = join_path_cmd(tab, "/", d->pipe[i][0]);
			closedir(d->folder);
			return (1);
		}
		d->entry = readdir(d->folder);
	}
	return (0);
}

int	set_return(t_data *d, char ***tab, int ret, int i)
{
	*tab = ft_leak_2(*tab);
	d->ret = ret;
	if (ret == 127 && d->pipe[i])
	{
		write(2, "minishell: ", 11);
		ft_putstr_fd(*d->pipe[i], 2);
		write(2, ": command not found\n", 20);
	}
	return (ret);
}

int	file_exist(int i, t_data *d)
{
	char			**tab;
	int				j;

	j = -1;
	d->pipe[i] = expression_without_redir(d->pipe[i]);
	if (!d->pipe[i])
		return (1);
	if (d->pipe[i][0][0] == '/' || d->pipe[i][0][0] == '.')
		return (0);
	tab = ft_split(find_var("PATH", d), ":");
	if (tab != NULL)
	{
		while (tab[++j])
		{
			d->folder = opendir(tab[j]);
			if (d->folder)
			{
				d->entry = readdir(d->folder);
				if (loop_check_if_file_exist(d, tab[j], i))
					return (set_return(d, &tab, 0, i));
				closedir(d->folder);
			}
		}
	}
	return (set_return(d, &tab, 127, i));
}
