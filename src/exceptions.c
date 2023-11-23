/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:10:11 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:10:12 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_lst_index(t_list *lst_head, int id);

static t_boolean	ordened_in_other_way(t_push_swap *ps)
{
	t_list		*aux;
	t_boolean	ordened;
	int			i;

	ordened = FALSE;
	i = 0;
	aux = ps->a;
	while (aux->next)
	{
		if (aux->id > aux->next->id)
		{
			if (aux->id == ft_lstsize(ps->a) && aux->next->id == 1)
				ordened = TRUE;
			i++;
		}
		aux = aux->next;
	}
	if (ordened == TRUE && i == 1 && ps->a->id > ft_lstlast(ps->a)->id)
	{
		set_first(ps, get_lst_index(ps->a, 1));
		return (TRUE);
	}
	return (FALSE);
}

static void	ft_size_three(t_push_swap *ps)
{
	if (ps->a->id == 1)
	{
		ft_swap(&ps->a, A);
		ft_rotate(&ps->a, A);
	}
	else if (ps->a->id == 2)
		ft_swap(&ps->a, A);
	else if (ps->a->id == 3)
	{
		ft_rotate(&ps->a, A);
		ft_swap(&ps->a, A);
	}
}

static void	ft_size_four(t_push_swap *ps)
{
	set_first(ps, get_lst_index(ps->a, 4));
	ft_push(ps, B);
	if (ordened_in_other_way(ps) == FALSE)
		ft_size_three(ps);
	ft_push(ps, A);
	ft_rotate(&ps->a, A);
}

static void	ft_size_five(t_push_swap *ps)
{
	set_first(ps, get_lst_index(ps->a, 5));
	ft_push(ps, B);
	if (ordened_in_other_way(ps) == FALSE)
		ft_size_four(ps);
	ft_push(ps, A);
	ft_rotate(&ps->a, A);
}

t_boolean	exceptions(t_push_swap *ps)
{
	if (ordened_in_other_way(ps) == TRUE)
		return (TRUE);
	if (ft_lstsize(ps->a) == 2)
		ft_swap(&ps->a, A);
	if (ft_lstsize(ps->a) == 3)
		ft_size_three(ps);
	if (ft_lstsize(ps->a) == 4)
		ft_size_four(ps);
	if (ft_lstsize(ps->a) == 5)
		ft_size_five(ps);
	return ((ft_lstsize(ps->a) <= 5));
}
