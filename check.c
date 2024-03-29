/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:22:10 by iarikupu          #+#    #+#             */
/*   Updated: 2022/06/13 07:30:58 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_args(const char *s, t_stuff *all)
{
	int	i;

	i = 0;
	if (!s)
		error_exit(all, NULL);
	while (s[i])
	{
		if (!(ft_isnum(s[i])) && !(s[i] == '-' || s[i] == '+' || s[i] == ' '))
			error_exit(all, NULL);
		i++;
	}
	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (i == ft_strlen(s))
		return (0);
	return (1);
}

void	validate(const char *str, t_stuff *all)
{
	int	i;

	i = 0;
	if (!check_args(str, all))
		return ;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && (str[i] == '-' || str[i] == '+'))
		{
			i++;
			if (!ft_isnum(str[i]))
				error_exit(all, NULL);
			while (str[i] && ft_isnum(str[i]))
				i++;
		}
		while (str[i] && ft_isnum(str[i]))
			i++;
		if (str[i] && (str[i] == '-' || str[i] == '+'))
			error_exit(all, NULL);
	}
}
