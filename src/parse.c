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

	i = 0;
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
		if ((s[i] == '-' || s[i] == '+') && i == 0)
		{
			i++;
			continue ;
		}
		if (ft_isdigit (s[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_boolean	is_ordeneds(char **argv)
{
	int	i;
	int	j;

	i = 0;
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

t_boolean	ft_parse(char **input)
{
	int				i;

	i = 0;
	while (input[i])
	{
		if (is_integer (input[i]) == FALSE)
			return (FALSE);
		else if (ft_atoi (input[i]) == 0 && ft_strcmp (input[i], "0") != 0)
			return (FALSE);
		i++;
	}
	if (is_repeat(input) == TRUE)
		return (FALSE);
	if (is_ordeneds(input) == TRUE)
		return (FALSE);
	return (TRUE);
}
