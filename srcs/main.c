/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:09:14 by nda-roch          #+#    #+#             */
/*   Updated: 2026/06/05 17:49:39 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			start;
	t_node		*stack_a;
	t_node		*stack_b;
	t_config	config;
	t_bench		bench;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	start = parse_flags(argv, &config);
	if (!argv[start])
		return (0);
	if (validate_args(argv, start) == 0)
		return (0);
	build_stack(argc, argv, start, &stack_a);
	if (is_sorted(&stack_a, &config, &bench) == 1)
		return (free_stack(&stack_a), 0);
	route_sorting(&stack_a, &stack_b, config, &bench);
	if (config.bench_mode == 1)
		benchmark(&bench);
	return (free_stack(&stack_a), 0);
}
