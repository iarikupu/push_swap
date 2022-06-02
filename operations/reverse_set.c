/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:31:22 by iarikupu          #+#    #+#             */
/*   Updated: 2022/03/07 12:31:22 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_stuff *st, int pr)
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
		st->a[st->size_a - 1] = swp[0];
		while (i < st->size_a - 1)
		{
			st->a[i] = swp[i + 1];
			i++;
		}
		free(swp);
		if (pr)
			ft_putstr_fd("rra\n", 1);
	}
}

void	ft_rrb(t_stuff *st, int pr)
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
		st->b[st->size_b - 1] = swp[0];
		while (i < st->size_b - 1)
		{
			st->b[i] = swp[i + 1];
			i++;
		}
		free(swp);
		if (pr)
			ft_putstr_fd("rrb\n", 1);
	}
}
void	ft_rrr(t_stuff *st)
{
	ft_rra(st, 0);
	ft_rrb(st, 0);
	ft_putstr_fd("rrr\n", 1);
}
