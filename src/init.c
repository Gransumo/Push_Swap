/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:09:04 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:09:08 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_parse_int(char *n)
{
	int	*i;

	i = (int *)malloc (sizeof(int));
	if (i == NULL)
		return (NULL);
	*i = ft_atoi (n);
	return (i);
}

static void	set_id(t_list **lst, int id)
{
	t_list	*lst_aux;
	t_list	*tmp;

	lst_aux = *lst;
	tmp = lst_aux;
	while (tmp->id != 0 && tmp->next != NULL)
		tmp = tmp->next;
	while (lst_aux)
	{
		if (*(int *)tmp->content > *(int *)lst_aux->content && lst_aux->id == 0)
			tmp = lst_aux;
		lst_aux = lst_aux->next;
	}
	tmp->id = id;
}

static void	init_id(t_list **lst)
{
	t_list	*lst_aux;
	int		id;

	id = 1;
	lst_aux = *lst;
	while (lst_aux)
	{
		lst_aux->id = 0;
		lst_aux = lst_aux->next;
	}
	lst_aux = *lst;
	while (id <= ft_lstsize(*lst))
	{
		set_id(&lst_aux, id);
		id++;
	}
}

char	**argv_join(int argc, char **argv)
{
	int		i;
	char	*input;
	char	*result;
	char	**split;

	split = NULL;
	i = 0;
	result = "";
	while (++i < argc)
	{
		input = ft_strjoin(argv[i], " ");
		result = ft_strjoin(result, input);
		free(input);
	}
	split = ft_split(result, ' ');
	free(result);
	return (split);
}

void	init_stack(char **input, t_push_swap *ps)
{
	int	i;
	int	*node_content;

	node_content = NULL;
	i = 0;
	while (input[i])
	{
		node_content = ft_parse_int (input[i]);
		if (node_content == NULL)
		{
			ft_free(input);
			error (ps);
		}
		ft_lstadd_back (&ps->a, ft_lstnew (node_content));
		i++;
	}
	init_id(&ps->a);
	ft_free(input);
}
