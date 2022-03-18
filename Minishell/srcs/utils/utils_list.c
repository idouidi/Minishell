/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:28:26 by user42            #+#    #+#             */
/*   Updated: 2021/12/15 18:55:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	env_var_already_exist(t_data *d)
{
	t_env	*tmp;

	tmp = d->head;
	while (tmp)
	{
		if (ft_strcmp(d->name, tmp->name) == 0)
		{
			if (d->value != NULL)
			{
				free(tmp->value);
				tmp->value = ft_strdup(d->value);
				d->name = ft_leak(d->name);
				d->value = ft_leak(d->value);
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	fill_list(t_data *d)
{
	t_env	*new;
	t_env	*tmp;

	tmp = d->head;
	if (env_var_already_exist(d) == 1)
		return ;
	new = malloc(sizeof(t_env));
	if (new)
	{
		new->name = ft_strdup(d->name);
		d->name = ft_leak(d->name);
		if (d->value != NULL)
		{
			new->value = ft_strdup(d->value);
			d->value = ft_leak(d->value);
		}
		else
			new->value = NULL;
		new->next = NULL;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

char	*change_env_var(t_data *d, char *s)
{
	t_env	*tmp;
	char	*stock;

	tmp = d->head;
	stock = ft_substr(s, 1, ft_strlen(s));
	while (tmp)
	{
		if (ft_strcmp(stock, tmp->name) == 0)
		{
			stock = ft_leak(stock);
			s = ft_leak(s);
			s = ft_strdup(tmp->value);
			return (s);
		}
		tmp = tmp->next;
	}
	stock = ft_leak(stock);
	s = ft_leak(s);
	s = ft_strdup("");
	return (s);
}

void	free_list(t_data *d)
{
	t_env	*tmp;

	tmp = NULL;
	while (d->head)
	{
		tmp = d->head;
		ft_leak(d->head->name);
		ft_leak(d->head->value);
		d->head = d->head->next;
		free(tmp);
	}
}
