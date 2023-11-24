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
			ft_rotate(&ps->a, A);
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
/* 
void	ft_leaks()
{
	system("leaks -q push_swap");
} */

t_push_swap	*init(int argc, char **argv)
{
	t_push_swap	*ps;
	char		**argv_aux;

	ps = (t_push_swap *)malloc (sizeof(t_push_swap));
	ps->a = NULL;
	ps->b = NULL;
	if (!ps)
		error (ps);
	argv_aux = argv_join(argc, argv);
	if (argv_aux == NULL)
		return (NULL);
	if (ft_parse(argv_aux) == FALSE)
	{
		ft_free(argv_aux);
		error (ps);
	}
	init_stack (argv_aux, ps);
	return (ps);
}

/* void	ft_leaks()
{
	system("leaks -q push_swap");
} */

int	main(int argc, char **argv)
{
	t_push_swap	*ps;

	ps = NULL;
	if (argc < 2 || argc > 501)
		error (ps);
	ps = init(argc, argv);
	if (exceptions(ps) == FALSE)
		ft_radix_sort(ps);
	delete_data(ps);
	return (0);
}
