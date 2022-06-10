/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:29:23 by iarikupu          #+#    #+#             */
/*   Updated: 2022/06/08 14:04:12 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stuff *all)
{
	int	min;
	int	i;

	i = 0;
	min = all->a[0];
	while (i < all->size_a)
	{
		if (all->a[i] < min)
			min = all->a[i];
		i++;
	}
	return (min);
}

int	find_max(t_stuff *all)
{
	int	max;
	int	i;

	i = 0;
	max = all->b[0];
	while (i < all->size_b)
	{
		if (all->b[i] > max)
			max = all->b[i];
		i++;
	}
	return (max);
}

int	get_pos(t_stuff *all, int n, int j)
{
	int	i;

	i = 0;
	if (j)
	{	
		while (i < all->size_a)
		{
			if (all->a[i] == n)
				return (i);
			i++;
		}
	}
	else
	{
		while (i < all->size_b)
		{
			if (all->b[i] == n)
				return (i);
			i++;
		}
	}
	return (i);
}

void	best_move(t_stuff *all, int n, int i)
{
	if (i)
	{
		if (all->size_a / 2 < get_pos(all, n, 1))
			ft_ra(all, 1);
		else
			ft_rra(all, 1);
	}
	else
	{
		if (all->size_b / 2 < get_pos(all, n, 0))
			ft_rb(all, 1);
		else
			ft_rrb(all, 1);
	}
}

void	temp_sort(t_stuff *all, t_sort *s, int n)
{
	int	i;

	i = 0;
	s->s = (int *)malloc((all->size_a) * sizeof(int));
	s->n = all->size_a;
	while (i < all->size_a)
	{
		s->s[i] = all->a[i];
		i++;
	}
	sorted(s);
	s->sn = s->s[(all->size_a / n) - 1];
	s->sn2 = s->s[(all->size_a / (2 * n))];
	free(s->s);
}
