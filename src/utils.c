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

void	p_matrix(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		ft_printf ("%s\n", m[i]);
		i++;
	}
}

void	ft_free(char **m)
{
	int	i;

	i = 0;
	while (m[i])
		free (m[i]);
	free (m);
}



