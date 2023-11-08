#include "push_swap.h"

void delete_data(t_push_swap *ps)
{
	t_list *aux;

	aux = ps->a;
	if (ps->a != NULL)
	{
		ft_lstiter(ps->a, free);
		while (ps->a)
		{
			aux = ps->a;
			ps->a = ps->a->next;
			free(aux);
		}
	}
	if (ps->b != NULL)
	{
		ft_lstiter(ps->b, free);
		while (ps->b)
		{
			aux = ps->b;
			ps->b = ps->b->next;
			free (aux);
		}
	}
}
void error_mensaje(error)
{
	ft_printf("%s", get_error_menssage[error]);
}

void	error(t_push_swap *ps, t_error_code error)
{
	delete_data(ps);
	if (error == OK)
		error = EC_UNDEFINED;
	error_mensaje(error);
	
	exit (error);
}
 