/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:22:42 by iarikupu          #+#    #+#             */
/*   Updated: 2022/06/02 15:24:01 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_num(int argc, char **argv, t_stuff *all, t_check *chk)
{
	join_arg(argc, argv, chk);
	extr_num(all, chk);
	check_dup(all, chk);
}

void	check_dup(t_stuff *all, t_check *chk)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->size_a)
	{
		j = 1;
		while (j + i < all->size_a)
		{
			if (all->a[i] == all->a[i + j])
				error_exit(all, chk);
			j++;
		}
		i++;
	}
}

void	extr_num(t_stuff *all, t_check *chk)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	chk->splited = ft_split(chk->joined);
	while (chk->splited[i])
	{
		ps_atoi(chk->splited[i], chk, all);
		i++;
	}
	chk->size = i;
	stack_init(all, chk);
	while (i--)
		all->a[j++] = ps_atoi(chk->splited[i], chk, all);
}

void	join_arg(int argc, char **argv, t_check *chk)
{
	int	i;

	i = 0;
	while (i++ < argc - 1)
	{
		chk->joined = ft_strjoin(chk->joined, argv[i]);
		chk->joined = ft_strjoin(chk->joined, " ");
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (0);
	ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (++i < ft_strlen(s1))
		ret[i] = s1[i];
	while (j < ft_strlen(s2))
		ret[i++] = s2[j++];
	ret[i] = 0;
	free(s1);
	return (ret);
}
