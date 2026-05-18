/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:36:49 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/18 18:58:38 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	long	args;

	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i])
	{
		if (is_valid_int(argv[i]) == 0)
			return (write(2, "Error\n", 6), 0);
		args = ft_atol(argv[i++]);
		if (args > INT_MAX || args < INT_MIN)
			return (write(2, "Error\n", 6), 0);
	}
	return (0);
}
