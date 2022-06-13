/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:25:38 by iarikupu          #+#    #+#             */
/*   Updated: 2022/06/13 07:32:03 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_rev(t_stuff *all)
{
	int	i;

	i = 0;
	if (all->size_a <= 2)
		return ;
	while (i < all->size_a - 1)
	{
		if (all->a[i] > all->a[i + 1])
			return ;
		i++;
	}
	i = 0;
	while (i++ < all->size_a - 1)
		ft_rra(all, 1);
}

int	check_sorted(t_stuff *all)
{
	int		sorted;
	int		i;

	sorted = 1;
	i = all->size_a;
	if (all->size_a <= 1)
		return (0);
	while (--i && sorted)
		if (all->a[i] > all->a[i - 1])
			sorted = 0;
	return (sorted);
}

void	sort_num(t_stuff *all, t_check *chk)
{
	if (check_sorted(all) || all->size_a == 1)
		ft_exit(all, chk);
	else if (all->size_a == 2)
		ft_sa(all, 1);
	else if (all->size_a == 3)
		sort_three(all);
	else if (all->size_a == 4)
		sort_four(all);
	else if (all->size_a == 5)
		sort_five(all);
	else if (all->size_a <= 10)
		sort_ten(all);
	else if (all->size_a > 10)
		sort_big(all);
}

int	main(int argc, char **argv)
{
	t_stuff	*all;
	t_check	*chk;
	int		i;

	if (argc < 2)
		return (0);
	chk = (t_check *)malloc(sizeof(t_check));
	all = (t_stuff *)malloc(sizeof(t_stuff));
	stuff_init(all);
	i = 0;
	while (++i < argc)
		validate(argv[i], all);
	check_init(chk);
	get_num(argc, argv, all, chk);
	sort_num(all, chk);
	ft_exit(all, chk);
}
