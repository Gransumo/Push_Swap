#include "push_swap.h"

/* void delete_data(t_push_swap *ps)
{}
void error_mensaje(error)
{} */

void	error(t_push_swap *ps, t_error_code error)
{
	//delete_data(ps);
	//error_mensaje(error);
	free(ps->a);
	exit (error);
}
 