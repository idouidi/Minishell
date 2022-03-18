/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:49:04 by user42            #+#    #+#             */
/*   Updated: 2021/06/04 03:54:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	ft_cd(t_data *d, char **s)
{
	int		i;
	char	*tmp;

	tmp = find_var("HOME", d);
	i = arg_cancel_redir(s);
	if (i == 0)
	{
		i = chdir(tmp);
		if (i != 0)
		{
			update_return_cmd("?", "1", d);
			perror("cd");
		}
	}
	else
	{
		s[i] = adjust_str(s[i]);
		if (chdir(s[i]) != 0 && ft_strcmp(s[i], "") != 0)
		{
			update_return_cmd("?", "1", d);
			perror("cd");
		}
	}
	return (0);
}
