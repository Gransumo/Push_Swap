
#include <stdio.h>
#include <unistd.h>

int main()
{
	int i;
	char **a;

	a = malloc(sizeof(char *) * 2 + 1);
	a[0] = "hola que tal";
	a[1] = "No me seas";
	a[3] = NULL;
	
	i = 0;
	while (a[i++])
		;
	printf("%i\n", i);
	return (0);
}
