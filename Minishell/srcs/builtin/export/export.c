/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 12:32:49 by user42            #+#    #+#             */
/*   Updated: 2021/06/04 02:42:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*add_variable(char *s, t_data *d)
{
	int		j;
	size_t	k;

	j = 0;
	s = adjust_str(s);
	while (s[j] && s[j] != '=')
		j++;
	d->name = ft_substr(s, 0, j);
	k = j + 1;
	if (k >= ft_strlen(s) && !ft_strchr(s, '='))
		d->value = NULL;
	else
	{
		while (s[k])
			k++;
		d->value = ft_substr(s, j + 1, k);
	}
	fill_list(d);
	return (s);
}

int	pars_export(char **s, t_data *d)
{
	int	i;
	int	error;

	i = 1;
	error = 0;
	while (s[i])
	{
		if (ft_strcmp(s[i], ">") != 0 && ft_strcmp(s[i], ">>") != 0
			&& ft_strcmp(s[i], "<") != 0 && ft_strcmp(s[i], "<<") != 0)
		{
			s[i] = adjust_str_export(s[i]);
			if (pars_export2(s[i]) == -1)
			{
				s[i] = adjust_str(s[i]);
				printf("export: « %s » : invalid identifier\n", s[i]);
				error = 1;
			}
			else
				s[i] = add_variable(s[i], d);
			i++;
		}
		else
			i += 2;
	}
	return (error);
}

int	ft_export(t_data *d, char **s)
{
	if (s[1] != NULL)
	{
		if (arg_cancel_redir(s) != 0)
		{
			if (pars_export(s, d) == 0)
				update_return_cmd("?", "0", d);
			else
				update_return_cmd("?", "1", d);
		}
		else
			print_export(d);
	}
	else
		print_export(d);
	return (0);
}
