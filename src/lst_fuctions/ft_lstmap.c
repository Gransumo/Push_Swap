/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <gcastro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:43:06 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 20:00:51 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*ls;
	t_stack	*new;

	ls = NULL;
	while (lst)
	{
		new = ft_lstnew ((*f)(lst -> value));
		if (new == NULL)
		{
			ft_lstclear (&ls, del);
			return (NULL);
		}
		ft_lstadd_back (&ls, new);
		lst = lst -> next;
	}
	return (ls);
}
