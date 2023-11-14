
#include <stdio.h>

int main(int argc, char **argv)
{
	int	i;
	int	j;
	i = 1;
	j = 1;
	while (argv[i++])
	{
		while (j < i)
		{
			if (argv[i] == argv[j])
			{
				printf("Error\n%i %i\n", i, j);
				return (0);
			}
			j++;
		}
	}
	return (0);
}