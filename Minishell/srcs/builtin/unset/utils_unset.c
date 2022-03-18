/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:09:33 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 17:23:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	pars_unset2(char *s)
{
	int	i;

	i = 0;
	if (ft_strchr(s, ' ') || ft_isdigit(s[0]) || ft_strchr(s, '=')
		|| (ft_strcmp(s, "") == 0))
		return (-1);
	if (s[1] && s[0] == 92 && ft_isdigit(s[1]))
		return (-1);
	while (s[i])
	{
		if ((s[i] == 92 && !ft_isalnum(s[i + 1]))
			|| (s[i] != 92 && !ft_isalnum(s[i]) && s[i] != '_'))
			return (-1);
		i++;
	}
	return (0);
}

int	check_error(char **s)
{
	if (pars_unset2(*s) == -1)
	{
		*s = adjust_str(*s);
		printf("unset: « %s » : invalid identifier\n", *s);
		return (-1);
	}
	return (0);
}

int	pars_unset(char **s, t_data *d)
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
			if (check_error(&s[i]) == 0)
				remove_variable(s[i], d);
			else
				error = 1;
			i += 1;
		}
		else
			i += 2;
	}
	return (error);
}
