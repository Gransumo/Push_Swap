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
t_boolean		ft_parse(char **input);
void			init_stack(char **input, t_push_swap *ps);
char			**argv_join(int argc, char **argv);
/* SORT */
t_boolean		exceptions(t_push_swap *ps);
/* ERROR */
void			error(t_push_swap *ps);
/* UTILS */
int				matrix_size(char **m);
void			ft_free(char **m);
t_boolean		is_finished(t_list *lst);
void			p_matrix(char **m);
void			delete_data(t_push_swap *ps);
/* MOVES */
void			ft_swap(t_list **lst, t_stack stack);
void			ft_push(t_push_swap *ps, t_stack stack);
void			ft_rotate( t_list **lst, t_stack stack);
void			ft_rrotate(t_list **lst, t_stack stack);
void			set_first(t_push_swap *ps, int index);

/* PRINTS */
void			ft_print_content(t_list *lst);
void			ft_print_id(t_list *lst);
#endif
