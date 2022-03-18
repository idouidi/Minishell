/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:37:32 by user42            #+#    #+#             */
/*   Updated: 2021/07/01 15:33:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

long	ft_atoi_exit(char *str)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] == 32 || str[i] == 10 || str[i] == 9 || str[i] == 12
		|| str[i] == 13 || str[i] == 11)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (res * neg);
		else
			res = (res * 10) + (long)(str[i] - '0');
		i++;
	}
	return (res * neg);
}

int	loop_check_each_digit(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i += 1;
	while (s[i] && ft_isdigit(s[i]))
		i += 1;
	if (s[i] != '\0')
		return (-1);
	return (0);
}

int	pars_exit(char **s, int *nb_arg, int *is_not_digit)
{
	long	ret;
	int		i;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (i == 1)
		{
			printf("bash: exit: too many arguments\n");
			*nb_arg = 1;
			return (1);
		}
		if (loop_check_each_digit(s[i]) == -1)
		{
			*is_not_digit = 1;
			return (2);
		}
		i += 1;
	}
	ret = ft_atoi_exit(s[0]);
	if (ret >= LLONG_MAX || ft_strcmp(s[0], "-") == 0
		|| ft_strcmp(s[0], "") == 0)
		return (-1);
	return (ret);
}

void	exec_exit(t_data *d, int ret, int is_not_digit)
{
	d->line = ft_leak(d->line);
	d->linespt = ft_leak_2(d->linespt);
	free_list(d);
	if (ret == -1 || is_not_digit == 1)
		printf("illegal number or the argument is not a numeric digit\n");
	exit((unsigned char)ret);
}

int	ft_exit(t_data *d, char **s)
{
	int		ret;
	int		is_not_digit;
	int		nb_arg;
	char	*tmp;
	int		i;

	nb_arg = 0;
	is_not_digit = 0;
	ret = 0;
	i = 0;
	printf("exit\n");
	i = arg_cancel_redir(s);
	if (i != 0)
		ret = pars_exit(&s[i], &nb_arg, &is_not_digit);
	tmp = ft_itoa((unsigned char)ret);
	update_return_cmd("?", tmp, d);
	tmp = ft_leak(tmp);
	if (nb_arg != 1)
		exec_exit(d, ret, is_not_digit);
	return (0);
}
