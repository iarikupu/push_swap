/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:29:03 by iarikupu          #+#    #+#             */
/*   Updated: 2022/03/07 12:29:03 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rb(t_stuff *st, int pr)
{
	size_t	i;
	int		*swp;

	if (st->size_b > 1)
	{
		swp = (int *)malloc(st->size_b * sizeof(int));
		i = 0;
		while (i < st->size_b)
		{
			swp[i] = st->b[i];
			i++;
		}
		i = 0;
		st->b[0] = swp[st->size_b - 1];
		while (++i < st->size_b)
			st->b[i] = swp[i - 1];
		free(swp);
		if (pr)
			ft_putstr_fd("rb\n", 1);
	}
}

void	ft_ra(t_stuff *st, int pr)
{
	size_t	i;
	int		*swp;

	if (st->size_a > 1)
	{
		swp = (int *)malloc(st->size_a * sizeof(int));
		i = 0;
		while (i < st->size_a)
		{
			swp[i] = st->a[i];
			i++;
		}
		i = 0;
		st->a[0] = swp[st->size_a - 1];
		while (++i < st->size_a)
			st->a[i] = swp[i - 1];
		free(swp);
		if (pr)
			ft_putstr_fd("ra\n", 1);
	}
}

void	ft_rr(t_stuff *st)
{
	ft_ra(st, 0);
	ft_rb(st, 0);
	ft_putstr_fd("rr\n", 1);
}
