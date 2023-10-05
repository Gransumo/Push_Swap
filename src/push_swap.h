#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef enum s_error {
	OK,
	EC_UNDEFINED,
	EC_MALLOC_ERROR,
	EC_MIN_INT,
	EC_MAX_INT,
	EC_NOT_INT_FOUND,
	EC_NUM_REPEAT,
	EC_SIZE
}	t_error_code;

typedef enum s_boolean
{
	FALSE = 0,
	TRUE = 1
}			t_boolean;

typedef struct s_push_swap
{
	t_list *a;
	t_list *b;
	t_list **a_head;
	t_list **b_head;
}				t_push_swap;

void	ft_free(char **m);
void	error(t_push_swap *ps, t_error_code error);
void	check_num_rules(char *s, t_push_swap *ps);
void	ft_free(char **m);
void	p_matrix(char **m);

#endif