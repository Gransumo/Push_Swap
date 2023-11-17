/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:09:16 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:09:18 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_print_id(t_list *lst)
{
	t_list	*lst_aux;

	lst_aux = lst;
	while (lst_aux)
	{
		ft_printf ("%d\n", lst_aux->id);
		lst_aux = lst_aux->next;
	}
} */

void	ft_print_content(t_list *lst)
{
	t_list	*lst_aux;

	lst_aux = lst;
	while (lst_aux)
	{
		ft_printf ("%d ", *(int *)lst_aux->content);
		lst_aux = lst_aux->next;
	}
}
