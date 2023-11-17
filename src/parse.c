/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:10:19 by gcastro-          #+#    #+#             */
/*   Updated: 2023/11/17 21:10:20 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_boolean	is_repeat(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv)
		return (FALSE);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp (argv[i], argv[j]) == 0)
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

static t_boolean	is_integer(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (FALSE);
	while (s[i])
	{
		if (ft_isdigit (s[i]) == 0 && s[i] != '-')
			return (FALSE);
		if (s[i] == '-' && i != 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_boolean	is_ordeneds(char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv)
		return (FALSE);
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi (argv[i]) > ft_atoi (argv[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

void	ft_parse(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_integer (argv[i]) == FALSE)
			error (EC_NOT_INT_FOUND);
		i++;
	}
	if (is_repeat(argv) == TRUE)
		error (EC_NUM_REPEAT);
	if (is_ordeneds(argv) == TRUE)
		error (EC_STACK_IS_ORDENED);
}
