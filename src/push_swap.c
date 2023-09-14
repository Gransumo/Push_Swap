
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

void	check_repeat(t_push_swap *ps, int n)
{
	while (ps->a)
	{
		if (n == ps->a->value)
			error("THERE IS A REPITED NUM");
		ps->a = ps->a->next;
	}
	
}

void	check_num_rules(char *s, t_push_swap *ps)
{
	int	i;

	i = 0;
	while (s[i++])
	{
		if (ft_isdigit(s[i]) == 0)
		{
			ft_lstclear(&ps->a, NULL);
			error("A NUMBER IS NOT AN INTEGER");
		}
	}
	if (ft_atoi(s) > INT_MAX)
	{
		ft_lstclear(&ps->a, NULL);
		error("A NUMBER IS GREATER THAN INT_MAX");
	}
	if (ft_atoi(s) < INT_MIN)
	{
		ft_lstclear(&ps->a, NULL);
		error("A NUMBER IS LOWER THAN INT_MIN");
	}
	check_repeat(ps, ft_atoi(s));
}

void	add_values(t_push_swap *ps, char **c_stack)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (c_stack[i])
	{
		check_num_rules(c_stack[i], ps);
		n = ft_atoi(c_stack[i]);
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
	char	**c_stack;
	int i;

	i = 1;
	c_stack = NULL;
	ps->a = NULL;
	while (i < argc)
	{
		c_stack = ft_split(argv[i], ' ');
		add_values(ps, c_stack);
		i++;
	}
}

t_push_swap init(int argc, char **argv)
{
	t_push_swap ps;

	ps.b = NULL;
	init_stack(argc, argv, &ps);
	return (ps);
}

int	main(int argc, char **argv)
{
	t_push_swap ps;

	ps = init(argc, argv);

	return (0);
}
