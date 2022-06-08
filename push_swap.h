/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarikupu <iarikupu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:27:32 by iarikupu          #+#    #+#             */
/*   Updated: 2022/06/02 15:28:37 by iarikupu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stuff
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stuff;

typedef struct s_check {
	char	*joined;
	char	**splited;
	int		size;
}				t_check;

typedef struct s_sort {
	int	*s;
	int	n;
	int	sn;
	int	sn2;
}				t_sort;

void	sort_num(t_stuff *st, t_check *chk);
void	check_rev(t_stuff *all);
int		check_sorted(t_stuff *st);

//Check
int		check_args(const char *s, t_stuff *all);
void	validate(const char *str, t_stuff *all);
int		ft_strlen(const char *str);
int		ft_isnum(int c);

//Helper

void	error_exit(t_stuff *all, t_check *chk);
int		wordcount(char *str);
char	**ft_split(char *str);
int		ps_atoi(const char *str, t_check *chk, t_stuff *all);
void	ft_exit(t_stuff *all, t_check *chk);

//Get_num
void	get_num(int argc, char **argv, t_stuff *all, t_check *chk);
void	join_arg(int argc, char **argv, t_check *chk);
void	extr_num(t_stuff *all, t_check *chk);
void	check_dup(t_stuff *all, t_check *chk);
char	*ft_strjoin(char *s1, char *s2);

//Init
void	stuff_init(t_stuff *all);
void	check_init(t_check *check);
void	stack_init(t_stuff *all, t_check *chk);
void	ft_putstr_fd(char *s, int fd);

//Operation
void	ft_pa(t_stuff *st);
void	ft_pb(t_stuff *st);
void	ft_rra(t_stuff *st, int pr);
void	ft_rrb(t_stuff *st, int pr);
void	ft_rrr(t_stuff *st);
void	ft_rb(t_stuff *st, int pr);
void	ft_ra(t_stuff *st, int pr);
void	ft_rr(t_stuff *st);
void	ft_sa(t_stuff *st, int pr);
void	ft_sb(t_stuff *st, int pr);
void	ft_ss(t_stuff *st);

//Sort_helper
int		find_min(t_stuff *all);
int		find_max(t_stuff *all);
int		get_pos(t_stuff *all, int n, int j);
void	best_move(t_stuff *all, int n, int i);
void	temp_sort(t_stuff *all, t_sort *sr, int n);

//Sort_helper2
int		closest_chunk(t_stuff *all, t_sort *sr);
int		in_chunk(t_stuff *all, t_sort *sr);
void	push_all_b(t_stuff *all);
void	sorted(t_sort *s);

//Sorter
void	sort_three(t_stuff *all);
void	sort_four(t_stuff *all);
void	sort_five(t_stuff*all);
void	sort_ten(t_stuff *all);
void	sort_big(t_stuff *all);

#endif
