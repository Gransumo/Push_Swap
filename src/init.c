#include "push_swap.h"

static int	*ft_parse_int(char *n)
{
	int	*i;

	i = (int *)malloc (sizeof(int));
	if (i == NULL)
		return (NULL);
	*i = ft_atoi (n);
	free (n);
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

static void	add_values(t_push_swap *ps, char **args)
{
	int		i;
	int		*node_value;

	i = 0;
	node_value = NULL;
	while (args[i])
	{
		node_value = ft_parse_int (args[i]);
		if (node_value == NULL)
		{
			ft_free (args);
			delete_data(ps);
			error (EC_MALLOC_ERROR);
		}
		ft_lstadd_back (&ps->a, ft_lstnew (node_value));
		i++;
	}
	free(args);
}



void	init_id(t_list **lst)
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

void	init_stack(int argc, char **argv, t_push_swap *ps)
{
	int		i;

	i = 1;
	while (i < argc)
		add_values (ps, ft_split (argv[i++], ' '));
	init_id(&ps->a);
	
}
