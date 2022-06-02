#include "push_swap.h"

void    stuff_init(t_stuff *all)
{
    all->a = NULL;
    all->b = NULL;
    all->size_a = 0;
    all->size_b = 0; 
}

void    check_init(t_check *check)
{
    check->joined = (char *)malloc(1);
    check->size = 0;
    check->splited = NULL;  
}

void	stack_init(t_stuff *all, t_check *chk)
{
	all->size_a = chk->size;
	all->size_b = 0;
	all->a = (int *)malloc((chk->size) * sizeof(int));
	all->b = (int *)malloc((chk->size) * sizeof(int));
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!s)
		return ;
	l = ft_strlen(s);
	write(fd, s, l);
}