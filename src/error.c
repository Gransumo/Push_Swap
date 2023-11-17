/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:09:48 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:09:49 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_data(t_push_swap *ps)
{
	if (ps->a != NULL)
		ft_lstclear(&ps->a, free);
	if (ps->b != NULL)
		ft_lstclear(&ps->b, free);
}

void	error(t_error_code error)
{
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

	if (error == OK)
		error = EC_UNDEFINED;
	ft_printf("%s\n", g_error_menssage[error]);
	exit (0);
}
 