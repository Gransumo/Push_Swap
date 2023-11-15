#include "push_swap.h"

void	ft_radix_sort(t_push_swap *ps) {
	t_list	*aux;

	aux = ps->a;
	while (is_finished(ps->a) == 0)
	{
		set_order(ps);
		ft_swap_head_list(ps);
		move_id_bits(ps->a);
	}
}

t_push_swap	init(int argc, char **argv)
{
	t_push_swap	ps;

	ps.a = NULL;
	ps.b = NULL;
	init_stack (argc, argv, &ps);
	init_id(&ps.a);
	return (ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	//atexit(ft_leaks);
	if (argc < 1 || argc > 501)
		error (EC_WRONG_ARGS_NUM);
	ft_parse(argc, argv);
	ps = init(argc, argv);
	//exceptions(&ps);
	ft_radix_sort(&ps);
	ft_printf("\n\n");
	ft_print_content(ps.a);
	ft_printf("\nB\n");
	ft_print_content(ps.b);
	delete_data(&ps);
	error(FINISH_PROGRAM);
	return (0);
}
