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

void	ft_rra(t_stuff *all, int pr)
{
	int	i;
	int	*swp;

	if (all->size_a > 1)
	{
		swp = (int *)malloc(all->size_a * sizeof(int));
		i = 0;
		while (i < all->size_a)
		{
			swp[i] = all->a[i];
			i++;
		}
		i = 0;
		all->a[all->size_a - 1] = swp[0];
		while (i < all->size_a - 1)
		{
			all->a[i] = swp[i + 1];
			i++;
		}
		free(swp);
		if (pr)
			ft_putstr_fd("rra\n", 1);
	}
}

void	ft_rrb(t_stuff *all, int pr)
{
	int	i;
	int	*swp;

	if (all->size_b > 1)
	{
		swp = (int *)malloc(all->size_b * sizeof(int));
		i = 0;
		while (i < all->size_b)
		{
			swp[i] = all->b[i];
			i++;
		}
		i = 0;
		all->b[all->size_b - 1] = swp[0];
		while (i < all->size_b - 1)
		{
			all->b[i] = swp[i + 1];
			i++;
		}
		free(swp);
		if (pr)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_rrr(t_stuff *all)
{
	ft_rra(all, 0);
	ft_rrb(all, 0);
	ft_putstr_fd("rrr\n", 1);
}
