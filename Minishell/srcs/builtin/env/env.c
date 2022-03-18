/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:59:37 by user42            #+#    #+#             */
/*   Updated: 2021/05/31 15:17:41 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_env(t_data *d)
{
	t_env	*tmp;

	tmp = d->head;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "?") != 0 && tmp->value != NULL)
			printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

int	ft_env(t_data *d, char **s)
{
	int	i;

	i = arg_cancel_redir(s);
	if (i != 0)
	{
		printf("env: %s: No such file or directory\n", s[i]);
		update_return_cmd("?", "127", d);
	}
	else
	{
		print_env(d);
		update_return_cmd("?", "0", d);
	}
	return (0);
}
