
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

t_stack *list_init(t_stack *list)
{
	list = NULL;
	return (list);
}

void	ft_free(char **mx)
{
	int	i;

	i = 0;
	while (mx[i])
	{
		free (mx[i]);
		i++;
	}
	free (mx);
}

char	**mat_concat(char **m1, char **m2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m1[i++])
		;
	while (m2[j++])
		;
	m1 = malloc(sizeof(char *) * (i + j) - 1);
	j = 0;
	while (m2[j] != NULL)
		m1[i + j] = m2[j++];
	m1[i + j] = NULL;
	ft_free (m2);
}

char	**get_char_stack(int argc, char **argv)
{
	char	**stack;
	char	**b_stack;
	int		i;

	i = 1;
	while (i <= argc)
	{
		b_stack = ft_split(argv[i], ' ');
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
t_stack *get_stack(int argc, char **argv)
{
	char	**stack;
	t_stack	list;
	stack = get_char_stack(argc, argv);
}

t_push_swap *init_vars(int argc, char **argv)
{
	t_push_swap ps;

	ps.a = list_init(ps.a);
	ps.b = list_init(ps.b);

	ps.a = get_stack(argc, argv);
	if (ps.a == NULL)
		return (NULL);
	return (&ps);
}

int	main(int argc, char **argv)
{
	t_push_swap *ps;

	ps = init_vars(argc, argv);
	if (ps == NULL)
		return (0);
	return (0);
}
