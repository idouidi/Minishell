/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:56:31 by othabchi          #+#    #+#             */
/*   Updated: 2022/02/07 12:05:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	init_builtin_str(t_data *d)
{
	d->builtin_str[0] = "echo";
	d->builtin_str[1] = "cd";
	d->builtin_str[2] = "pwd";
	d->builtin_str[3] = "export";
	d->builtin_str[4] = "unset";
	d->builtin_str[5] = "env";
	d->builtin_str[6] = "exit";
	d->builtin_str[7] = NULL;
}

void	init_builtin_func(t_data *d)
{
	d->builtin_func[0] = &ft_echo;
	d->builtin_func[1] = &ft_cd;
	d->builtin_func[2] = &ft_pwd;
	d->builtin_func[3] = &ft_export;
	d->builtin_func[4] = &ft_unset;
	d->builtin_func[5] = &ft_env;
	d->builtin_func[6] = &ft_exit;
}

void	init_struct(t_data *d)
{
	d->line = NULL;
	d->linespt = NULL;
	d->path = NULL;
	d->head = NULL;
	d->name = NULL;
	d->value = NULL;
	d->redir = NULL;
	d->fd_stdout = 1;
	d->fd_stdin = 0;
	d->open_the_door = 0;
	d->ret = 0;
	d->sys_func = 0;
}

void	init_env_var(t_data *d, char **envp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (envp[i])
	{
		d->new_ = malloc(sizeof(t_env));
		if (d->new_)
		{
			while (envp[i][j] && envp[i][j] != '=')
				j++;
			d->new_->name = ft_substr(envp[i], 0, j);
			k = j + 1;
			while (envp[i][k])
				k++;
			d->new_->value = ft_substr(envp[i], j + 1, k--);
			d->new_->next = d->head;
			d->head = d->new_;
		}
		i++;
		j = 0;
	}
}

int	main(int ac, char *av[], char *envp[])
{
	t_data	d;

	(void)ac;
	(void)av;
	g_data = &d;
	if (!*envp)
	{
		ft_putstr_fd("Minishell: can't start with an empty environment\n", 2);
		return (1);
	}
	init_builtin_str(&d);
	init_builtin_func(&d);
	init_struct(&d);
	init_env_var(&d, envp);
	d.name = ft_strdup("?");
	d.value = ft_strdup("0");
	fill_list(&d);
	minishell(&d, envp);
	return (0);
}
