
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

void	p_mat (char **m)
{
	int i;

	i = 0;
	while (m[i])
		ft_printf("%s\n", m[i]);
}



void	add_values(t_push_swap *ps, char **args)
{
	int		i;
	char	*n;

	i = 0;
	n = NULL;
	while (args[i])
	{
		check_num_rules(args[i], ps);
		n = ft_strdup(args[i]);
		ft_lstadd_back(&ps->a, ft_lstnew(n));
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
	int		i;
	
	i = 1;
	while (i < argc)
	{
		add_values(ps, ft_split(argv[i], ' '));
		i++;
	}
}

void	ft_printvalue(void *n) {
	ft_printf("%s\n", n);
}

t_push_swap init(int argc, char **argv)
{
	t_push_swap ps;

	ps.a = NULL;
	ps.b = NULL;
	init_stack(argc, argv, &ps);
	ft_lstiter(ps.a, ft_printvalue);
	return (ps);
}

int	main(int argc, char **argv)
{
	t_push_swap ps;

	if (argc < 2 || argc > 500)
		error (&ps, EC_WRONG_ARGS_NUM);
	ps = init(argc, argv);

	return (0);
}
