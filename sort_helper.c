#include "push_swap.h"

int		find_min(t_stuff *all)
{
	int		min;
	int     i;

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

int		find_max(t_stuff *all)
{
	int		max;
	int     i;

	i = 0;
	max = all->a[0];
	while (i < all->size_a)
	{
		if (all->a[i] > max)
			max = all->a[i];
		i++;
	}
	return (max);
}

int     get_pos(t_stuff *all, int n)
{
	int i;

	i = 0;
	while (i < all->size_a)
	{
		if (all->a[i] == n)
			return (i);
		i++;
	}
	return (i);
}

void	best_move(t_stuff *all, int n, int i)
{
	if(i)
	{
		if (all->size_a / 2 < get_pos(all, n))
			ft_ra(all, 1);
		else
			ft_rra(all, 1);
	}
	else
	{
		if (all->size_b / 2 < get_pos(all, n))
			ft_rb(all,1);
		else
			ft_rrb(all, 1);
	}
}

void	temp_sort(t_stuff *all, t_sort *s, int n)
{
	size_t	i;

	i = 0;
	s->s = (int *)malloc((all->size_a) * sizeof(int));
	while (i < all->size_a)
	{
		s->s[i] = all->a[i];
		i++;
	}
	sorted(all, s);
	s->sn = s->s[(all->size_a / n) - 1];
	free(s->s);
}
