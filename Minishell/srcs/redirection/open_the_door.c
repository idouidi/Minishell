/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_the_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:38:21 by user42            #+#    #+#             */
/*   Updated: 2021/12/15 21:11:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	putstr_in_last_fd(char *line, int fd)
{
	ft_putstr_fd(line, fd);
	write(fd, "\n", 1);
}

int	match_key(t_data *d, char **door, int count)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (i < count)
	{
		write(1, "> ", 2);
		get_next_line(0, &line);
		if (g_data->open_the_door == 2)
		{
			line = ft_leak(line);
			return (-1);
		}
		if (!ft_strcmp(line, door[i]))
			i += 1;
		else if (i + 1 == count)
			putstr_in_last_fd(line, d->fd_stdin);
		line = ft_leak(line);
	}
	return (0);
}

int	exec_match_key(t_data *d, char **door, int count)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		g_data->pid_open_the_door = pid;
		match_key(d, door, count);
		door = ft_leak_2(door);
		g_data->open_the_door = 0;
		exit (0);
	}
	else
		waitpid(pid, &status, 0);
	return (0);
}

void	open_the_door(t_data *d, char **expression)
{
	int		count;
	char	**door;

	d->open_the_door = 0;
	count = nb_key(expression);
	if (count == 0)
		return ;
	d->open_the_door = 1;
	d->fd_stdin = open(".here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	door = malloc(sizeof(char *) * (count + 1));
	door = set_key(door, expression);
	exec_match_key(d, door, count);
	door = ft_leak_2(door);
}
