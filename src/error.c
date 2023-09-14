#include "push_swap.h"

int	error(char *message)
{
	char	*mss;

	mss = ft_strjoin ("ERROR\n", message);
	perror (mss);
	free (mss);
	exit (EXIT_FAILURE);
}
 