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
	EC_STACK_IS_ORDENED,
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
[EC_STACK_IS_ORDENED] = "STACK IS ORDENED\n",
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
/* RADIX SORT */
void	set_order(t_push_swap *ps);
void	ft_swap_head_list(t_push_swap *ps);
void	move_id_bits(t_list *lst);
/* ERROR */
void	ft_parse(int argc, char **argv);
void	error(t_error_code error);
void	delete_data(t_push_swap *ps);
/* UTILS */
void	ft_free(char **m);
void	p_matrix(char **m);
//int		is_finished(t_list *lst);
int		get_lst_index(t_list *lst_head, t_list *node);
/* MOVES */
void	ft_swap(t_list **lst);
void	ft_push(t_push_swap *ps, t_stack stack);
void	ft_rotate(t_list **lst);
void	ft_rrotate(t_list **lst);
/* PRINTS */
void	ft_print_id(t_list *lst);
void	ft_print_content(t_list *lst);
#endif
