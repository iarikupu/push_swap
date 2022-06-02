/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:29:47 by iarikupu          #+#    #+#             */
/*   Updated: 2022/06/02 15:29:53 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest_chunk(t_stuff *all, t_sort *sr)
{
	int	i;

	i = all->size_a;
	while (i--)
		if (all->a[i] <= sr->sn)
			break ;
	return (all->a[i]);
}

int	in_chunk(t_stuff *all, t_sort *sr)
{
	int	i;

	i = 0;
	while (i < all->size_a)
		if (all->a[i++] <= sr->sn)
			return (1);
	return (0);
}

void	push_all_b(t_stuff *all)
{
	while (all->size_b)
	{
		if (all->b[all->size_b - 1] == find_max(all))
			ft_pa(all);
		else
			best_move(all, find_max(all), 0);
	}
}

void	sorted(t_stuff *all, t_sort *s)
{
	int	i;
	int	j;

	i = -1;
	while (++i < all->size_a)
	{
		j = -1;
		while (++j < all->size_a)
		{
			if (s->s[i] < s->s[j])
			{
				s->s[i] = s->s[i] ^ s->s[j];
				s->s[j] = s->s[i] ^ s->s[j];
				s->s[i] = s->s[i] ^ s->s[j];
			}
		}
	}
}
