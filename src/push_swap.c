/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:09:30 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:10:34 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_content(t_list *lst);

static void	set_order(t_push_swap *ps)
{
	int		i;

	i = ft_lstsize(ps->a);
	while (i-- != 0)
	{
		if ((ps->a->id & 1) == 0)
			ft_push(ps, B);
		else
			ft_rotate(ps, &ps->a, A);
	}
	while (ps->b)
		ft_push(ps, A);
}

static void	move_id_bits(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		aux->id = aux->id >> 1;
		aux = aux->next;
	}
}

static void	ft_radix_sort(t_push_swap *ps)
{
	while (is_finished(ps->a) == FALSE)
	{
		set_order(ps);
		move_id_bits(ps->a);
	}
}

t_push_swap	init(int argc, char **argv)
{
	t_push_swap	ps;

	ps.a = NULL;
	ps.b = NULL;
	ps.moves = 0;
	init_stack (argc, argv, &ps);
	return (ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc <= 1 || argc > 501)
		error (EC_WRONG_ARGS_NUM);
	ft_parse(argc, argv);
	ps = init(argc, argv);
	if (exceptions(&ps) == FALSE)
		ft_radix_sort(&ps);
	ft_print_content(ps.a);
	ft_printf("\nmoves: %d\n", ps.moves);
	delete_data(&ps);
	error(FINISH_PROGRAM);
	return (0);
}
