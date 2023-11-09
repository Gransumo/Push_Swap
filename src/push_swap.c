#include "push_swap.h"
/* -------------- INIT ----------------------------- */
int	*ft_parse_int(char *n)
{
	int	*i;

	i = (int *)malloc (sizeof(int));
	if (i == NULL)
		return (NULL);
	*i = ft_atoi (n);
	free (n);
	return (i);
}

void	add_values(t_push_swap *ps, char **args)
{
	int		i;
	int		*node_value;

	i = 0;
	node_value = NULL;
	while (args[i])
	{
		check_num_rules (args[i], ps);
		node_value = ft_parse_int (args[i]);
		if (node_value == NULL)
		{
			ft_free (args);
			error (ps, EC_MALLOC_ERROR);
		}
		ft_lstadd_back (&ps->a, ft_lstnew (node_value));
		i++;
	}
	free(args);
}

void	init_stack(int argc, char **argv, t_push_swap *ps)
{
	int		i;

	i = 1;
	while (i < argc)
		add_values (ps, ft_split (argv[i++], ' '));
}

t_push_swap	init(int argc, char **argv)
{
	t_push_swap	ps;

	ps.a = NULL;
	ps.b = NULL;
	init_stack (argc, argv, &ps);
	return (ps);
}
/* ------------------------------------------------------------------------------- */

void	set_id(t_list **lst)
{
	t_list	*lst_aux;
	t_list	*tmp;
	int		id;
	
	id = 1;
	lst_aux = *lst;
	tmp = lst_aux;
	while (id < ft_lstsize(*lst))
	{
		while (lst_aux != NULL)
		{
			if (tmp == NULL && lst_aux->id == 0)
				tmp = lst_aux;
			ft_printf("tmp: %i  aux: %i,  ", (*(int *)tmp->content), (*(int *)lst_aux->content));
			if ((*(int *)tmp->content) > (*(int *)lst_aux->content) && lst_aux->id == 0)
				tmp = lst_aux;
			lst_aux = lst_aux->next;
		}
		ft_printf("\n");
		tmp->id = id;
		id++;
		lst_aux = *lst;
		tmp = NULL;
	}
}
		/* while (lst_aux)
		{
			if ((*(int *)lst_aux->content) < (*(int *)tmp->content) && lst_aux->id == 0)
				tmp = lst_aux;
			ft_printf("id: %d\n\t%i\n", lst_aux->id, *(int *)lst_aux->content);
			lst_aux = lst_aux->next;
		} */


void	ft_print_id(t_list *lst)
{
	t_list	*lst_aux;

	lst_aux = lst;
	while (lst_aux)
	{
		ft_printf ("%d\n", lst_aux->id);
		lst_aux = lst_aux->next;
	}
}

void	ft_print_content(t_list *lst)
{
	t_list	*lst_aux;

	lst_aux = lst;
	while (lst_aux)
	{
		ft_printf ("%d\n", *(int *)lst_aux->content);
		lst_aux = lst_aux->next;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2 || argc >= 502)
		error (&ps, EC_WRONG_ARGS_NUM);
	ps = init(argc, argv);
	set_id(&ps.a);
	ft_print_content(ps.a);
	ft_printf("\n\n\n");
	ft_print_id(ps.a);
	error(&ps, FINISH_PROGRAM);
	return (0);
}
