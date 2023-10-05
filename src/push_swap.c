
#include "push_swap.h"
/* 
	FASES DEL PPROGRAMA

	1. PROCESAR INFORMACIÓN
		1. ASIGNAR LOS VALORES A UN A LISTA CONNVIRTIENDOLOS TODOS A INT.
			a. Split " " a todos los argumentos.
			b. Verificar que SOLO hay caracteres numericos.


	2. CHECKER DE ERRORES
		1. NO SON ENTEROS
		2. NUMERO MAYOR QUE UN INT
		3. NUMEROS DUPLICADOS
	3. 


 */

/* FUNCION VERRIFICAR REPETIDOS */

void	add_values(t_push_swap *ps, char *arg)
{
	int i;
	int n;
	char **m;

	i = 0;
	n = 0;
	m = ft_split(arg, ' ');
	while (m[i])
	{
		check_num_rules(m[i], ps);
		n = ft_atoi(m[i]);
		ft_lstadd_back(&ps->a, ft_lstnew(&n));
		i++;
	}
}

/**
 * 		GET_STACK
 * 
 * 	get_stack is a fuction which returns a stack-list whose values are the
 * 	param <b>argv</b> vales in the same order. If a param has many values
 * 	they are splited and joined separately.
 * 
 * 	The fuction verify these norms:
 *		1. Only numeric values.
 *		2. All values has to be integers.
 *		3. There should be not repeated values.
 * 
 * @param	argc argv len
 * @param	argv matrix with the values to proccess
 * @return	The Stack with values, if any rue is not met, returns <b>NULL</b>
 */
void	init_stack(int argc, char **argv, t_push_swap *ps)
{
	int i;

	i = 1;
	while (i < argc)
	{
		add_values(ps, argv[i]);
		i++;
	}
}

void	ft_printvalue(void *n) {
	ft_printf("%i\n", &n);
}

t_push_swap init(int argc, char **argv)
{
	t_push_swap ps;

	ps.b = NULL;
	init_stack(argc, argv, &ps);
	ft_lstiter(ps.a, &ft_printvalue);
	return (ps);
}

int	main(int argc, char **argv)
{
	t_push_swap ps;

	ps = init(argc, argv);

	return (0);
}
