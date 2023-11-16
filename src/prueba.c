
#include <stdio.h>

int main(int argc, char **argv)
{
	int	i;
	int	j;
	i = 1;
	j = 1;
	while (argv[i++])
	{
		printf("argv[%i]:\t%s\n", i, argv[i]);
	}
	return (0);
}