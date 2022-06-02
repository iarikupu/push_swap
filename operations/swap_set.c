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

void	ft_sa(t_stuff *st, int pr)
{
	if (st->size_a > 1)
	{
		st->a[st->size_a - 1] = st->a[st->size_a - 1] ^ st->a[st->size_a - 2];
		st->a[st->size_a - 2] = st->a[st->size_a - 1] ^ st->a[st->size_a - 2];
		st->a[st->size_a - 1] = st->a[st->size_a - 1] ^ st->a[st->size_a - 2];
		if (pr)
			ft_putstr_fd("sa\n", 1);
	}
}

void	ft_sb(t_stuff *st, int pr)
{
	if (st->size_b > 1)
	{
		st->b[st->size_b - 1] = st->b[st->size_b - 1] ^ st->b[st->size_b - 2];
		st->b[st->size_b - 2] = st->b[st->size_b - 1] ^ st->b[st->size_b - 2];
		st->b[st->size_b - 1] = st->b[st->size_b - 1] ^ st->b[st->size_b - 2];
		if (pr)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ft_ss(t_stuff *st)
{
	ft_sa(st, 0);
	ft_sb(st, 0);
	ft_putstr_fd("ss\n", 1);
}
