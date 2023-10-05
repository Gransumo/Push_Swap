
#include "push_swap.h"

void p_matrix(char **m)
{
	int i;

	i = 0;
	while (m[i])
	{
		ft_printf("%s\n", m[i]);
		i++;
	}
}

void ft_free(char **m)
{
	int i;

	i = 0;
	while (m[i])
		free(m[i]);
	free(m);
}
