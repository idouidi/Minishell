/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:40:41 by othabchi          #+#    #+#             */
/*   Updated: 2021/12/16 10:04:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	close_redir(char *s, t_data *d)
{
	if (!ft_strcmp(s, ">") || !ft_strcmp(s, ">>"))
		close(d->fd_stdout);
	else
		close (d->fd_stdin);
}

int	fd_stdin(t_data *d, char *s, char *file)
{
	if (!ft_strcmp(s, "<"))
		d->fd_stdin = open(file, O_RDONLY);
	else if ((!ft_strcmp(s, "<<")))
		d->fd_stdin = open(".here_doc", O_CREAT | O_RDONLY, 0644);
	if (d->fd_stdin < 0)
	{
		if (!ft_strcmp(s, "<<"))
			perror(".here_doc");
		else
			perror(file);
		return (-1);
	}
	return (0);
}

int	fd_stdout(t_data *d, char *s, char *file)
{
	if (ft_strcmp(s, ">>") == 0)
		d->fd_stdout = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else
		d->fd_stdout = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (d->fd_stdout < 0)
	{
		perror(file);
		return (-1);
	}
	return (0);
}

int	update_redirection(t_data *d, char *s, char *file)
{
	if (!ft_strcmp(s, ">") || !ft_strcmp(s, ">>"))
	{
		if (fd_stdout(d, s, file) == -1)
			return (-1);
	}	
	else if (!ft_strcmp(s, "<") || !ft_strcmp(s, "<<"))
	{
		if (fd_stdin(d, s, file) == -1)
			return (-1);
	}
	return (0);
}

int	redirection(t_data *d, char **s)
{
	int	i;

	i = 0;
	open_the_door(d, s);
	while (s[i])
	{
		if (!ft_strcmp(s[i], ">") || !ft_strcmp(s[i], ">>")
			|| !ft_strcmp(s[i], "<") || !ft_strcmp(s[i], "<<"))
		{
			if (!ft_strcmp(s[i], ">") || !ft_strcmp(s[i], ">>"))
				if (d->fd_stdout >= 3)
					close_redir(s[i], d);
			if (!ft_strcmp(s[i], "<") || !ft_strcmp(s[i], "<<"))
				if (d->fd_stdin >= 3)
					close_redir(s[i], d);
			if (update_redirection(d, s[i], s[i + 1]) == -1)
				return (-1);
		}
		i += 1;
	}
	return (0);
}
