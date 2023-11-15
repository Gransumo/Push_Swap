#include "push_swap.h"

static t_boolean	is_repeat(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv)
		return (FALSE);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp (argv[i], argv[j]) == 0)
			{
				ft_printf ("argv[%i]: %s argv[%i]: %s\n", i, argv[i], j, argv[j]);
				return (TRUE);
			}
			j++;
		}
		i++;
	}
	return (FALSE);
}

static t_boolean	is_integer(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (FALSE);
	while (s[i])
	{
		if (ft_isdigit (s[i]) == 0 && s[i] != '-')
			return (FALSE);
		if (s[i] == '-' && i != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	over_int(const char *s)
{
	int	n;

	if (!s)
		return ;
	n = ft_atoi (s);
	if (n > INT_MAX)
		error (EC_MAX_INT);
	if (n < INT_MIN)
		error (EC_MIN_INT);
}

static t_boolean is_ordeneds(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv)
		return (FALSE);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi (argv[i]) > ft_atoi (argv[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

void	ft_parse(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_integer (argv[i]) == FALSE)
			error (EC_NOT_INT_FOUND);
		over_int (argv[i]);
		i++;
	}
	if (is_repeat(argv) == TRUE)
		error (EC_NUM_REPEAT);
	if (is_ordeneds(argv) == TRUE)
		error (EC_STACK_IS_ORDENED);
}
