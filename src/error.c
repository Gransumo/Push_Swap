#include "push_swap.h"

static void free_list(t_list *lst) {
    t_list *current = lst;
    t_list *next;

    while (current != NULL) {
        next = current->next;
        free(current->content);
        free(current);
        current = next; 
    }
}

void delete_data(t_push_swap *ps)
{
	if (ps->a != NULL)
		free_list(ps->a);
	if (ps->b != NULL)
		free_list(ps->b);
}
void error_mensaje(error)
{
	ft_printf("%s\n", g_error_menssage[error]);
}

void	error(t_push_swap *ps, t_error_code error)
{
	delete_data(ps);
	if (error == OK)
		error = EC_UNDEFINED;
	error_mensaje(error);
	exit (error);
}
 