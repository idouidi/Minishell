/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:02:47 by user42            #+#    #+#             */
/*   Updated: 2021/06/02 17:26:01 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	pars_export3(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == 92 && !ft_isalnum(s[i + 1]) && s[i + 1] != '=')
			|| (s[i] != 92 && !ft_isalnum(s[i]) && s[i] != '_'))
			return (-1);
		i++;
	}
	return (0);
}

int	pars_export2(char *s)
{
	int	i;

	i = 0;
	if (ft_isdigit(s[0]) || s[0] == '=' || ft_strcmp(s, "") == 0)
		return (-1);
	if (s[1] && s[0] == 92 && (ft_isdigit(s[1]) || s[1] == '='))
		return (-1);
	if (ft_strchr(s, '='))
	{
		while (s[i] && s[i] != '=')
		{
			if ((s[i] == 92 && !ft_isalnum(s[i + 1]) && s[i + 1] != '=')
				|| (s[i] != 92 && !ft_isalnum(s[i]) && s[i] != '_'))
				return (-1);
			i++;
		}
	}
	else
		if (pars_export3(s) == -1)
			return (-1);
	return (0);
}
