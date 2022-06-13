/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:24:10 by iarikupu          #+#    #+#             */
/*   Updated: 2022/06/13 08:35:08 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stuff *all, t_check *chk)
{
	write(2, "Error\n", 6);
	ft_exit(all, chk);
}

void	ft_exit(t_stuff *all, t_check *chk)
{
	if (all)
	{
		free(all->a);
		free(all->b);
		free(all);
	}
	if (chk)
	{
		free(chk->joined);
		while (chk->size > 0)
			free(chk->splited[--chk->size]);
		if (chk->splited)
			free(chk->splited);
		free(chk);
	}
	exit(0);
}

int	wordcount(char *s)
{
	int	i;
	int	words;

	if (!s[0])
		return (0);
	i = 0;
	words = 0;
	while (s[i] && s[i] == ' ')
		i++;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			words++;
			while (s[i] && s[i] == ' ')
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != ' ')
		words++;
	return (words);
}

char	**ft_split(char *str)
{
	char	**ret;
	int		wc;
	int		i;
	int		j;

	wc = wordcount(str);
	ret = (char **)malloc((wc + 1) * sizeof(char *));
	if (!ret)
		return (0);
	i = 0;
	while (i < wc)
	{
		while (*str && *str == ' ')
			str++;
		j = 0;
		while (str[j] && str[j] != ' ')
			j++;
		ret[i] = (char *)malloc(j + 1);
		j = 0;
		while (*str && *(str) != ' ')
			ret[i][j++] = *str++;
		ret[i++][j] = 0;
	}
	ret[i] = 0;
	return (ret);
}

int	ps_atoi(const char *str, t_check *chk, t_stuff *all)
{
	int		i;
	int		sym;
	size_t	nb;

	i = 0;
	sym = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sym = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - 48;
		if ((sym == -1 && nb > 2147483648) || (sym == 1 && nb > 2147483647))
			error_exit(all, chk);
	}
	return (nb * sym);
}
