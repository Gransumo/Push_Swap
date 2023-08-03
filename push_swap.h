#ifndef	PUSH_SWAP
# define PUSH_SWAP
# include <unistd.h>
# include "Libft/libft.h"

typedef enum s_boolean
{
	FALSE = 0,
	TRUE = 1
}			t_boolean;

typedef struct s_stack
{
	int value;
	int index;
	struct s_stack *next;
}		t_stack;

typedef struct s_push_swap
{
	t_stack *a;
	t_stack *b;
}				t_push_swap;


#endif