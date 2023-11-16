#include "push_swap.h"

void	set_order(t_push_swap *ps)
{
	int		i;

	i = ft_lstsize(ps->a);
	while (i-- != 0)
	{
		if ((ps->a->id & 1) == 0)
			ft_push(ps, B);
		else
			ft_rotate(ps, &ps->a);
	}
	while (ps->b)
		ft_push(ps, A);
}

void	move_id_bits(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		aux->id = aux->id >> 1;
		aux = aux->next;
	}
}