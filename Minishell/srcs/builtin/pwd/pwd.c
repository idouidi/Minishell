/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:25:57 by othabchi          #+#    #+#             */
/*   Updated: 2021/06/28 14:38:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_pwd(t_data *d, char **s)
{
	(void)s;
	d->path = getcwd(d->path, 1024);
	ft_putstr_fd(d->path, d->fd_stdout);
	ft_putstr_fd("\n", d->fd_stdout);
	update_return_cmd("?", "0", d);
	d->path = ft_leak(d->path);
	return (0);
}
