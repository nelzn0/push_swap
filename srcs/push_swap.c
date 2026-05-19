/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:36:49 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/19 20:01:28 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	long	args;
	t_node	*new;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc <= 1)
		return (0);
	while (argv[i])
	{
		if (is_valid_int(argv[i]) == 0)
			return (write(2, "Error\n", 6), 0);
		args = ft_atol(argv[i]);
		if (args > INT_MAX || args < INT_MIN)
			return (write(2, "Error\n", 6), 0);
		if (has_duplicate(argv, i) == 1)
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	while ((argc - 1) > 1)
	{
		new = new_node((int)ft_atol(argv[argc - 1]));
		move_to_top(&stack_a, new);
		argc--;
	}
	if (is_sorted(&stack_a) == 1)
		return (free_stack(&stack_a), 0);
	//placeholder
	normalize(&stack_a);
	radix(&stack_a, &stack_b);
	return (free_stack(&stack_a), 0);
}
