/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 00:28:50 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 15:51:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_env	*init_tab(t_env *tab, t_data *d)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = d->head;
	while (tmp)
	{
		i += 1;
		tmp = tmp->next;
	}
	tab = malloc(sizeof(t_env) * i);
	tmp = d->head;
	i = 0;
	while (tmp)
	{
		tab[i].name = ft_strdup(tmp->name);
		if (tmp->value != NULL)
			tab[i].value = ft_strdup(tmp->value);
		else
			tab[i].value = NULL;
		tmp = tmp->next;
		i += 1;
	}
	d->nb_element = i;
	return (tab);
}

void	swap(t_env *a, t_env *b)
{
	t_env	set;

	set = *a;
	*a = *b;
	*b = set;
}

t_env	*sort_tab(t_env *tab, t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (d->nb_element >= 2)
	{
		while (i < d->nb_element)
		{
			while (j < d->nb_element)
			{
				if (ft_strcmp(tab[i].name, tab[j].name) <= 0)
					j++;
				else
				{
					swap(&tab[i], &tab[j]);
					j = i + 1;
				}
			}
			i++;
			j = i + 1;
		}
	}
	return (tab);
}

void	set_tab(t_env **tab, t_data *d)
{
	*tab = init_tab(*tab, d);
	*tab = sort_tab(*tab, d);
}

void	print_export(t_data *d)
{
	t_env	*tab;
	int		i;

	i = 0;
	set_tab(&tab, d);
	while (i < d->nb_element)
	{
		if (ft_strcmp(tab[i].name, "?") != 0)
		{
			ft_putstr_fd("declare -x ", d->fd_stdout);
			ft_putstr_fd(tab[i].name, d->fd_stdout);
			if (tab[i].value != NULL)
			{
				ft_putstr_fd("=\"", d->fd_stdout);
				ft_putstr_fd(tab[i].value, d->fd_stdout);
				ft_putstr_fd("\"\n", d->fd_stdout);
			}
			else
				ft_putstr_fd(" \n", d->fd_stdout);
		}
		ft_leak(tab[i].name);
		ft_leak(tab[i].value);
		i++;
	}
	free(tab);
}
