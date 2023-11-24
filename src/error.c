/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:09:48 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:09:49 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_data(t_push_swap *ps)
{
	if (ps->a != NULL)
		ft_lstclear(&ps->a, free);
	if (ps->b != NULL)
		ft_lstclear(&ps->b, free);
	if (ps != NULL)
		free(ps);
}

void	error(t_push_swap *ps)
{
	ft_printf("Error\n");
	if (ps)
		delete_data(ps);
	exit (0);
}
