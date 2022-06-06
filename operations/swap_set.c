/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap _set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:42:52 by iarikupu          #+#    #+#             */
/*   Updated: 2022/03/07 12:42:52 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stuff *all, int pr)
{
	if (all->size_a > 1)
	{
		all->a[all->size_a - 1] = all->a[all->size_a - 1] ^ all->a[all->size_a - 2];
		all->a[all->size_a - 2] = all->a[all->size_a - 1] ^ all->a[all->size_a - 2];
		all->a[all->size_a - 1] = all->a[all->size_a - 1] ^ all->a[all->size_a - 2];
		if (pr)
			ft_putstr_fd("sa\n", 1);
	}
}

void	ft_sb(t_stuff *all, int pr)
{
	if (all->size_b > 1)
	{
		all->b[all->size_b - 1] = all->b[all->size_b - 1] ^ all->b[all->size_b - 2];
		all->b[all->size_b - 2] = all->b[all->size_b - 1] ^ all->b[all->size_b - 2];
		all->b[all->size_b - 1] = all->b[all->size_b - 1] ^ all->b[all->size_b - 2];
		if (pr)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ft_ss(t_stuff *all)
{
	ft_sa(all, 0);
	ft_sb(all, 0);
	ft_putstr_fd("ss\n", 1);
}
