/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:27:55 by iarikupu          #+#    #+#             */
/*   Updated: 2022/03/07 12:27:55 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_stuff *all)
{
	if (all->size_b > 0)
	{
		all->a[all->size_a++] = all->b[--all->size_b];
		ft_putstr_fd("pa\n", 1);
	}
}

void	ft_pb(t_stuff *all)
{
	if (all->size_a > 0)
	{
		all->b[all->size_b++] = all->a[--all->size_a];
		ft_putstr_fd("pb\n", 1);
	}
}
