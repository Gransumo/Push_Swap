#include "push_swap.h"

void	ft_print_id(t_list *lst)
{
	t_list	*lst_aux;

	lst_aux = lst;
	while (lst_aux)
	{
		ft_printf ("%d\n", lst_aux->id);
		lst_aux = lst_aux->next;
	}
}

void	ft_print_content(t_list *lst)
{
	t_list	*lst_aux;

	lst_aux = lst;
	while (lst_aux)
	{
		ft_printf ("%d\n", *(int *)lst_aux->content);
		lst_aux = lst_aux->next;
	}
}