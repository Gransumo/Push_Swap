#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef enum s_boolean
{
	FALSE = 0,
	TRUE = 1
}			t_boolean;

typedef struct s_list
{
	t_node *cabeza;
}	t_list;

typedef struct s_push_swap
{
	t_list *a;
	t_list *b;
}				t_push_swap;

int	error(char *message);

#endif