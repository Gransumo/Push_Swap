#include "push_swap.h"

/* static void free_list(t_list *lst) {
    t_list *current = lst;
    t_list *next;

	ft_lstclear(&lst, free);
    while (current != NULL) {
        next = current->next;
        free(current->content);
        free(current);
        current = next; 
    }
} */

void delete_data(t_push_swap *ps)
{
	if (ps->a != NULL)
		ft_lstclear(&ps->a, free);
	if (ps->b != NULL)
		ft_lstclear(&ps->b, free);
}
void error_mensaje(error)
{
	ft_printf("%s\n", g_error_menssage[error]);
}

void	error(t_error_code error)
{
	//delete_data(ps);
	if (error == OK)
		error = EC_UNDEFINED;
	error_mensaje(error);
	exit (error);
}
 