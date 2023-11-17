/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:10:03 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:10:05 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_boolean	is_finished(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		if (aux->id != 0)
			return (FALSE);
		aux = aux->next;
	}
	return (TRUE);
}

void	p_matrix(char **m)
{
	int	i;

	i = 0;
	while (m[i])
	{
		ft_printf ("%s\n", m[i]);
		i++;
	}
}

void	ft_free(char **m)
{
	int	i;

	i = 0;
	while (m[i])
		free (m[i]);
	free (m);
}

int	get_lst_index(t_list *lst_head, int id)
{
	int		index;
	t_list	*aux;

	index = 1;
	aux = lst_head;
	while (aux)
	{
		if (aux->id == id)
			return (index);
		index++;
		aux = aux->next;
	}
	return (-1);
}
