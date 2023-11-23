/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:09:54 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:09:55 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst, t_stack stack)
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
	ft_printf("s%c\n", stack);
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
	ft_printf("p%c\n", stack);
}

void	ft_rotate(t_list **lst, t_stack stack)
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
	ft_printf("r%c\n", stack);
}

void	ft_rrotate(t_list **lst, t_stack stack)
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
	ft_printf("rr%c\n", stack);
}

void	set_first(t_push_swap *ps, int index)
{
	int	i;

	i = 1;
	if (index <= ft_lstsize(ps->a) / 2 + (ft_lstsize(ps->a) % 2))
	{
		while (i++ < index)
			ft_rotate(&ps->a, A);
	}
	else
	{
		while (i++ <= (ft_lstsize(ps->a) - index + 1))
			ft_rrotate(&ps->a, A);
	}
}
