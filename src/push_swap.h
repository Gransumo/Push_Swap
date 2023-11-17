/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:09:41 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:10:28 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "../Libft/libft.h"

typedef enum e_stack {
	A = 'a',
	B = 'b'
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

typedef enum s_boolean
{
	FALSE = 0,
	TRUE = 1
}			t_boolean;

typedef struct s_push_swap
{
	t_list	*a;
	t_list	*b;
	int		moves;
}				t_push_swap;
/* INIT */
void		init_stack(int argc, char **argv, t_push_swap *ps);
/* SORT */
t_boolean	exceptions(t_push_swap *ps);
/* ERROR */
void		ft_parse(int argc, char **argv);
void		error(t_error_code error);
void		delete_data(t_push_swap *ps);
/* UTILS */
void		ft_free(char **m);
t_boolean	is_finished(t_list *lst);
/* MOVES */
void		ft_swap(t_push_swap *ps, t_list **lst, t_stack stack);
void		ft_push(t_push_swap *ps, t_stack stack);
void		ft_rotate(t_push_swap *ps, t_list **lst, t_stack stack);
void		ft_rrotate(t_push_swap *ps, t_list **lst, t_stack stack);
void		set_first(t_push_swap *ps, int index);
#endif
