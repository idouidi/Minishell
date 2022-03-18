/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:55:57 by othabchi          #+#    #+#             */
/*   Updated: 2021/12/15 21:10:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	here_doc_signal(void)
{
	update_return_cmd("?", "130", g_data);
	g_data->open_the_door = 2;
	if (g_data->pid_open_the_door == 0)
	{
		write(1, "\n", 1);
		exit(0);
	}
}

void	sig_handler(int signal)
{
	if (signal == 3)
		return ;
	if (signal == -1)
	{
		write(2, "exit\n", 5);
		exit(0);
	}
	else
	{
		g_data->line = ft_leak(g_data->line);
		if (g_data->open_the_door == 0)
		{
			update_return_cmd("?", "130", g_data);
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			if (g_data->sys_func != 1)
				rl_redisplay();
		}
		else
			here_doc_signal();
	}
}

void	next_cmd(t_data *d, char **envp)
{
	int		i;
	char	**expression;

	i = 0;
	expression = NULL;
	while (d->linespt[i])
	{
		expression = split_expression(&d->linespt[i], d);
		if (*expression)
		{
			if (there_is_pipe(expression))
				exec_pipe(d, expression, envp);
			else if (builtin(d, expression) == -1)
				exec_pipe(d, expression, envp);
		}
		while (d->linespt[i] && ft_strcmp(d->linespt[i], ";"))
			i++;
		if (d->linespt[i])
			i++;
		expression = ft_leak_2(expression);
		d->sys_func = 0;
		d->ret = 0;
	}
}

void	minishell(t_data *d, char **envp)
{
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	d->save_stdin = dup(0);
	d->save_stdout = dup(1);
	while (1)
	{
		d->line = readline("$> ");
		add_history(d->line);
		if (!d->line)
			sig_handler(-1);
		else if (!check_line(d))
		{
			d->linespt = ft_split_minishell(d, d->line);
			if (d->linespt)
				next_cmd(d, envp);
		}
		d->fd_stdout = 1;
		d->fd_stdin = 0;
		d->line = ft_leak(d->line);
		d->linespt = ft_leak_2(d->linespt);
	}
}
