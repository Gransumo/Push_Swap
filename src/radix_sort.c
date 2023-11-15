#include "push_swap.h"

static void	ft_move(t_push_swap *ps, int index)
{
	int		size;
	int		i;

	size = ft_lstsize(ps->a);
	i = 1;
	if (index > size)
		return ;
	if (index <= ((size / 2) + (size % 2)))
	{
		while (i++ < index)
			ft_rotate(&ps->a);
	}
	else
	{
		while (i++ <= size - index + 1)
			ft_rrotate(&ps->a);
	}
	ft_push(ps, B);
	ft_rotate(&ps->b);
}

void	set_order(t_push_swap *ps)
{
	t_list	*lst;

	lst = ps->a;
	while (lst)
	{
		if ((lst->id & 1) == 0)
		{
			ft_move(ps, get_lst_index(ps->a, lst));
			lst = ps->a;
			continue ;
		}
		lst = lst->next;
	}
	lst = ps->a;
	while (lst)
	{
		if ((lst->id & 1) == 1)
		{
			ft_move(ps, get_lst_index(ps->a, lst));
			lst = ps->a;
			continue ;
		}
		lst = lst->next;
	}
}
void	ft_swap_head_list(t_push_swap *ps)
{
	t_list	*aux;

	aux = ps->a;
	ps->a = ps->b;
	ps->b = aux;
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