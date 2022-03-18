/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 12:15:13 by user42            #+#    #+#             */
/*   Updated: 2021/11/24 23:38:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	first_link(t_data *d, char *s)
{
	t_env	*remove;
	t_env	*tmp;

	tmp = d->head;
	if (ft_strcmp(s, tmp->name) == 0)
	{
		remove = tmp;
		ft_leak(tmp->name);
		ft_leak(tmp->value);
		if (tmp->next)
			d->head = tmp->next;
		free(remove);
		return (1);
	}
	return (0);
}

void	remove_variable(char *s, t_data *d)
{
	t_env	*tmp;
	t_env	*remove;

	tmp = d->head;
	while (tmp)
	{
		if (tmp == d->head && first_link(d, s) == 1)
			break ;
		remove = tmp->next;
		if (remove && ft_strcmp(s, remove->name) == 0)
		{
			ft_leak(remove->name);
			if (remove->value)
				ft_leak(remove->value);
			if (remove->next == NULL)
				tmp->next = NULL;
			else
				tmp->next = remove->next;
			free(remove);
			break ;
		}
		else
			tmp = tmp->next;
	}
}

int	ft_unset(t_data *d, char **s)
{
	if (s[1] != NULL)
	{
		if (arg_cancel_redir(s) != 0)
		{
			if (pars_unset(s, d) == 0)
				update_return_cmd("?", "0", d);
			else
				update_return_cmd("?", "1", d);
		}
	}
	return (0);
}
