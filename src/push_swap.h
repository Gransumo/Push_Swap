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
	EC_WRONG_ARGS_NUM,
	EC_MALLOC_ERROR,
	EC_MIN_INT,
	EC_MAX_INT,
	EC_NOT_INT_FOUND,
	EC_NUM_REPEAT,
	EC_SIZE
}	t_error_code;

static const char	*get_error_menssage[EC_SIZE] = {
	[EC_UNDEFINED] = " UNDEFINED\n",
	[EC_WRONG_ARGS_NUM] = "WRONG ARGS NUM. ONLY (1- 500) PLEASE\n",
	[EC_MALLOC_ERROR] = "ERROR ON MALLOC\n",
	[EC_MIN_INT] = "A NUMBER SMALLER THAN INT_MIN WAS FOUND\n",
	[EC_MAX_INT] = "A NUMBER BIGGER THAN MAX_MIN WAS FOUND\n",
	[EC_NOT_INT_FOUND] = "A NOT_INT WAS FOUND\n",
	[EC_NUM_REPEAT] = "A REPEAT NUMBER WAS FOUND\n",
};

typedef enum s_boolean
{
	FALSE = 0,
	TRUE = 1
}			t_boolean;

typedef struct s_push_swap
{
	t_list *a;
	t_list *b;
}				t_push_swap;

void	ft_free(char **m);
void	error(t_push_swap *ps, t_error_code error);
void	check_num_rules(char *s, t_push_swap *ps);
void	ft_free(char **m);
void	p_matrix(char **m);

#endif