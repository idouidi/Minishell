/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_open_the_door.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 13:20:08 by user42            #+#    #+#             */
/*   Updated: 2021/12/15 19:31:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	nb_key(char **expression)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (expression[i])
	{
		if (!ft_strcmp("<<", expression[i]))
			count += 1;
		i += 1;
	}
	return (count);
}

char	**set_key(char **door, char **expression)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (expression[i])
	{
		if (!ft_strcmp("<<", expression[i]))
		{
			expression[i + 1] = adjust_str(expression[i + 1]);
			door[j++] = ft_strdup(expression[i + 1]);
		}
		i += 1;
	}
	door[j] = NULL;
	return (door);
}

static void	free_it(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

static int	separate_lines(char **line, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i += 1;
	*line = ft_substr(str, 0, i);
	if (!line)
	{
		free_it(&str);
		return (-1);
	}
	free_it(&str);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*str;
	char		buf[BUFFER_SIZE + 1];
	int			i;
	char		*tmp;

	str = ft_strdup("");
	tmp = str;
	while (!ft_strchr(str, '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			break ;
		buf[i] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		tmp = ft_leak(tmp);
	}
	if (tmp)
		tmp = ft_leak(tmp);
	return (separate_lines(line, str));
}
