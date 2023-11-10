#include "push_swap.h"

int	is_finished(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		if (aux->id != 0)
			return (0);
		aux = aux->next;
	}
	return (1);
}

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
	if (n == 0 && ft_strncmp (s, "0", 1) != 0)
		error (ps, EC_ATOI_ERROR);
	while (s[i])
	{
		if (ft_isdigit (s[i++]) == 0 && s[i - 1] != '-')
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
