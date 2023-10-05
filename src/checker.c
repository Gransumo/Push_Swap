
#include "push_swap.h"

static void	check_repeat(t_push_swap *ps, int n)
{
	while (ps->a)
	{
		if (ps->a->content == &n)
			error(ps, EC_NUM_REPEAT);
		ps->a = ps->a->next;
	}
	ps->a = *ps->a_head;
}

void	check_num_rules(char *s, t_push_swap *ps)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i++]) == 0)
			error(ps, EC_NOT_INT_FOUND);
	}
	if (ft_atoi(s) > INT_MAX)
		error(ps, EC_MAX_INT);
	if (ft_atoi(s) < INT_MIN)
		error(ps, EC_MIN_INT);
	if (ft_lstsize(ps->a) != 0)
		check_repeat(ps, ft_atoi(s));	
}