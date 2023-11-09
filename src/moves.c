#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*aux;

	aux = NULL;
	if (lst && ft_lstsize(*lst) > 1)
	{
		aux = (*lst)->next;
		(*lst)->next = aux->next;
		aux->next = *lst;
		*lst = aux;
	}
}

void	ft_push(t_push_swap *ps, t_stack stack)
{
	t_list	**first;
	t_list	**second;
	t_list	*aux;

	aux = NULL;
	if (stack == A)
	{
		first = &ps->a;
		second = &ps->b;
	}
	else
	{
		first = &ps->b;
		second = &ps->a;
	}
	if (*second)
	{	
		aux = (*second)->next;
		(*second)->next = *first;
		*first = *second;
		*second = aux;
	}
}

void	ft_rotate(t_list **lst)
{
	t_list	*aux;

	aux = NULL;
	if (lst && ft_lstsize(*lst) > 1)
	{
		aux = *lst;
		*lst = (*lst)->next;
		ft_lstlast(*lst)->next = aux;
		aux->next = NULL;
	}
}

void	ft_rrotate(t_list **lst)
{
	t_list	*aux;
	t_list	*last;

	aux = NULL;
	last = NULL;
	if (lst && ft_lstsize(*lst) > 1)
	{
		aux = *lst;
		last = ft_lstlast(*lst);
		last->next = *lst;
		*lst = last;
		while (aux->next != last)
			aux = aux->next;
		aux->next = NULL;
	}
}

void	ft_rr(t_push_swap *ps)
{
	ft_rotate(&ps->a);
	ft_rotate(&ps->b);
}

void	ft_rrr(t_push_swap *ps)
{
	ft_rrotate(&ps->a);
	ft_rrotate(&ps->b);
}
