/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:42:30 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:42:31 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*ls;

	while (*lst)
	{
		ls = (**lst).next;
		ft_lstdelone ((*lst), del);
		*lst = ls;
	}
	*lst = NULL;
}
