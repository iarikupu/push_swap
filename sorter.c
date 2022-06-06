/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:30:22 by iarikupu          #+#    #+#             */
/*   Updated: 2022/06/02 15:30:47 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stuff *all)
{
	if (all->a[0] < all->a[1] && all->a[0] < all->a[2] && all->a[2] < all->a[1])
		ft_rra(all, 1);
	else if (all->a[0] < all->a[1] && all->a[2] < all->a[0]
		&& all->a[2] < all->a[1])
	{
		ft_rra(all, 1);
		ft_sa(all, 1);
	}
	else if (all->a[1] < all->a[0] && all->a[1] < all->a[2]
		&& all->a[0] < all->a[2])
		ft_ra(all, 1);
	else if (all->a[0] < all->a[2] && all->a[1] < all->a[2])
	{
		ft_sa(all, 1);
		ft_rra(all, 1);
	}
	else
		ft_sa(all, 1);
}

void	sort_four(t_stuff *all)
{
	while (!check_sorted(all) && all->size_a == 4)
	{
		if (find_min(all) == all->a[3] && all->size_a == 4)
			ft_pb(all);
		else
			best_move(all, find_min(all), 1);
		if (all->size_a == 3)
		{
			sort_three(all);
			ft_pa(all);
		}
	}
}

void	sort_five(t_stuff *all)
{
	while (!check_sorted(all) && all->size_a == 5)
	{
		if (find_min(all) == all->a[4] && all->size_a == 5)
			ft_pb(all);
		else
			best_move(all, find_min(all), 1);
		if (all->size_a == 4)
		{
			sort_four(all);
			ft_pa(all);
		}
	}
}

void	sort_ten(t_stuff *all)
{
	while (!check_sorted(all))
	{
		if (find_min(all) == all->a[all->size_a - 1])
			ft_pb(all);
		else
			best_move(all, find_min(all), 1);
	}
	while (all->size_b)
		ft_pa(all);
}

void	sort_big(t_stuff *all)
{
	t_sort	*s;
	int		n;

	n = 5;
	s = (t_sort *)malloc(sizeof(t_sort));
	if (all->size_a > 100)
		n = 13;
	while (--n)
	{
		temp_sort(all, s, n);
		while (all->size_a)
		{
			if (all->a[all->size_a - 1] <= s->sn)
				ft_pb(all);
			else
				best_move(all, closest_chunk(all, s), 1);
			if (!in_chunk(all, s))
				break ;
		}
	}
	push_all_b(all);
	free(s);
}
