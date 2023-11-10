#include "push_swap.h"

t_push_swap	init(int argc, char **argv)
{
	t_push_swap	ps;

	ps.a = NULL;
	ps.b = NULL;
	init_stack (argc, argv, &ps);
	init_id(&ps.a);
	return (ps);
}
/* ------------------------------------------------------------------------------- */

int	get_lst_index(t_list *lst_head, t_list *node)
{
	int		index;
	t_list	*aux;

	index = 0;
	aux = lst_head;
	while (aux)
	{
		if (aux == node)
			return (index);
		index++;
		aux = aux->next;
	}
	return (-1);
}

void	ft_move(t_push_swap *ps, int index)
{
	int		size;
	int		i;
	t_list	*aux;

	size = ft_lstsize(ps->a);
	i = 1;
	aux = ps->a;
	if (index < size / 2)
	{
		while (i++ <= index)
			ft_rotate(&ps->a);
	}
	else
	{
		while (i++ < size - index)
			ft_rrotate(&ps->a);
	}
	ft_push(ps, B);
}

void	set_order(t_push_swap *ps)
{
	t_list	*lst;

	lst = ps->a;
	while (lst)
	{
		ft_printf("lst->id: %d\n", lst->id);
		if ((lst->id & 1) == 0)
		{	ft_printf("\tESTE SE MUEVE\n");
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

void	ft_radix_sort(t_push_swap *ps) {
	t_list	*aux;

	aux = ps->a;
	while (is_finished(ps->a) == 0)
	{
		set_order(ps);
		ft_swap_head_list(ps);
		move_id_bits(ps->a);
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	//atexit(ft_leaks);
	if (argc < 2 || argc >= 502)
		error (&ps, EC_WRONG_ARGS_NUM);
	ps = init(argc, argv);
	ft_radix_sort(&ps);
	ft_print_id(ps.a);
	ft_printf("\n\n");
	//set_order(&ps);
	ft_printf("\n\nA_id:\n");
	ft_print_id(ps.a);
	ft_printf("\n\nB_id:\n");
	ft_print_id(ps.b);
	ft_printf("\n\nHOLA");
	ft_print_content(ps.a);
	error(&ps, FINISH_PROGRAM);
	return (0);
}
