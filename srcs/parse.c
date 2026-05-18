/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:42:35 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/18 19:56:20 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int(char *str)
{
	if (str[0] == '+' || str[0] == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	has_duplicate(char **argv, int i)
{
	int		j;
	long	argi;
	long	argj;

	j = 1;
	while (j < i)
	{
		argi = ft_atol(argv[i]);
		argj = ft_atol(argv[j]);
		if (argi == argj)
			return (1);
		j++;
	}
	return (0);
}
