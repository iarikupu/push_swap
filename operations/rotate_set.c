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

void	ft_rb(t_stuff *all, int pr)
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
		all->b[0] = swp[all->size_b - 1];
		while (++i < all->size_b)
			all->b[i] = swp[i - 1];
		free(swp);
		if (pr)
			ft_putstr_fd("rb\n", 1);
	}
}

void	ft_ra(t_stuff *all, int pr)
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
		all->a[0] = swp[all->size_a - 1];
		while (++i < all->size_a)
			all->a[i] = swp[i - 1];
		free(swp);
		if (pr)
			ft_putstr_fd("ra\n", 1);
	}
}

void	ft_rr(t_stuff *all)
{
	ft_ra(all, 0);
	ft_rb(all, 0);
	ft_putstr_fd("rr\n", 1);
}
