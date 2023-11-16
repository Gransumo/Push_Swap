#include "push_swap.h"

/* void imprimirBinario(int numero)
{
    int bits = sizeof(numero) * 2;
    for (int i = bits - 1; i >= 0; i--) {
        int bit = (numero >> i) & 1;
        ft_printf("%d", bit);
    }
}

void	print_id_binary(t_list **lst)
{
	t_list	*aux;
	int		i;

	i = 0;
	aux = *lst;
	while (aux)
	{
		imprimirBinario(aux->id);
		ft_printf(" %i\n", *(int *)aux->content);
		aux = aux->next;
		i++;
	}
	ft_printf("size: %d\n", i);
} */

void	ft_radix_sort(t_push_swap *ps)
{
	t_list	*aux;

	aux = ps->a;
	while (is_finished(ps->a) == FALSE)
	{
		set_order(ps);
		move_id_bits(ps->a);
	}
}

t_push_swap	init(int argc, char **argv)
{
	t_push_swap	ps;

	ps.a = NULL;
	ps.b = NULL;
	ps.moves = 0;
	init_stack (argc, argv, &ps);
	init_id(&ps.a);
	return (ps);
}

void	ft_leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	atexit(ft_leaks);
	if (argc < 1 || argc > 501)
		error (EC_WRONG_ARGS_NUM);
	ft_parse(argc, argv);
	ps = init(argc, argv);
	//exceptions(&ps);
	ft_radix_sort(&ps);
	ft_print_content(ps.a);
	ft_printf("moves: %d\n", ps.moves);
	delete_data(&ps);
	error(FINISH_PROGRAM);
	return (0);
}
