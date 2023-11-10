#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../Libft/libft.h"

typedef enum e_stack {
	A,
	B
}	t_stack;

typedef enum e_error {
	OK,
	EC_UNDEFINED,
	EC_WRONG_ARGS_NUM,
	EC_MALLOC_ERROR,
	EC_MIN_INT,
	EC_MAX_INT,
	EC_NOT_INT_FOUND,
	EC_NUM_REPEAT,
	EC_ATOI_ERROR,
	FINISH_PROGRAM,
	EC_SIZE
}	t_error_code;

static const char	*g_error_menssage[EC_SIZE] = {
[EC_UNDEFINED] = " UNDEFINED\n",
[EC_WRONG_ARGS_NUM] = "WRONG ARGS NUM. ONLY (1- 500) PLEASE\n",
[EC_MALLOC_ERROR] = "ERROR ON MALLOC\n",
[EC_MIN_INT] = "A NUMBER SMALLER THAN INT_MIN WAS FOUND\n",
[EC_MAX_INT] = "A NUMBER BIGGER THAN MAX_MIN WAS FOUND\n",
[EC_NOT_INT_FOUND] = "A NOT_INT WAS FOUND\n",
[EC_NUM_REPEAT] = "A REPEAT NUMBER WAS FOUND\n",
[EC_ATOI_ERROR] = "ERROR ON ATOI\n",
[FINISH_PROGRAM] = "FINISHED"
};

typedef enum s_boolean
{
	FALSE = 0,
	TRUE = 1
}			t_boolean;

typedef struct s_push_swap
{
	t_list	*a;
	t_list	*b;
}				t_push_swap;
/* INIT */
t_push_swap	init(int argc, char **argv);
void	init_stack(int argc, char **argv, t_push_swap *ps);
void	init_id(t_list **lst);

/* ERROR */
void	error(t_push_swap *ps, t_error_code error);
/* UTILS */
void	ft_free(char **m);
void	check_num_rules(char *s, t_push_swap *ps);
void	p_matrix(char **m);
int		is_finished(t_list *lst);
/* MOVES */
void	ft_swap(t_list **lst);
void	ft_push(t_push_swap *ps, t_stack stack);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);
/* PRINTS */
void	ft_print_id(t_list *lst);
void	ft_print_content(t_list *lst);
#endif
