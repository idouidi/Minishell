/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:54:23 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 17:54:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*find_var(char *s, t_data *d)
{
	t_env	*tmp;

	tmp = d->head;
	while (tmp)
	{
		if (strcmp(s, tmp->name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	update_return_cmd(char *s1, char *s2, t_data *d)
{
	d->name = ft_strdup(s1);
	d->value = ft_strdup(s2);
	env_var_already_exist(d);
}
