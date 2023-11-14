#include "push_swap.h"

/* static void	is_repeat(int *n, int i)
{
	int	j;

	j = 0;
	if (!n)
		return ;
	while (n[j])
	{
		if (n[j] == i)
			error (EC_NUM_REPEAT);
		j++;
	}
} */

int	int_rules(const char *s)
{
	long int	i;

	i = ft_atoi (s);
	if (i == 0 && ft_strncmp (s, "0", 1) != 0)
		error (EC_ATOI_ERROR);
	while (s[i])
	{
		if (ft_isdigit (s[i++]) == 0 && ft_isdigit (s[i - 2]) == 1)
			error (EC_NOT_INT_FOUND);
	}
	if (i > INT_MAX)
		error (EC_MAX_INT);
	if (i < INT_MIN)
		error (EC_MIN_INT);
	return (i);
}

void	ft_parse(int argc, char **argv)
{
	int n[argc - 1];
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < argc)
	{
		n[i] = int_rules(argv[i + 1]);
		i++;
	}

}
