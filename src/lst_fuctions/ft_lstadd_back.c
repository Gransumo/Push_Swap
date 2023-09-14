/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <gcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:42:11 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 20:00:55 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*ls;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ls = ft_lstlast(*lst);
		ls -> next = new;
	}	
}
