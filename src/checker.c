#include "push_swap.h"

static void	check_repeat(t_push_swap *ps, char *n)
{
	t_list	*aux;

	aux = ps->a;
	if (ps->a != NULL)
	{
		while (aux)
		{
			if (ft_strncmp (aux->content, n, ft_strlen (n)) == 0)
				error (ps, EC_NUM_REPEAT);
			if (aux->next != NULL)
				aux = aux->next;
			else
				break ;
		}
	}
}

void	check_num_rules(char *s, t_push_swap *ps)
{
	int	i;
	int	n;

	i = 0;
	n = ft_atoi (s);
	while (s[i])
	{
		if (ft_isdigit (s[i++]) == 0)
			error (ps, EC_NOT_INT_FOUND);
	}
	if (ft_atoi (s) > INT_MAX)
		error (ps, EC_MAX_INT);
	if (ft_atoi (s) < INT_MIN)
		error (ps, EC_MIN_INT);
	if (ft_lstsize (ps->a) != 0)
		check_repeat (ps, s);
}
	//ft_printf("%s\n", ft_atoi(s));
