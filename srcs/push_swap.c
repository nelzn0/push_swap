/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:36:49 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/28 19:06:03 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flags(char **argv, t_config *config)
{
	int	i;

	config->strategy = 4;
	config->bench_mode = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			config->bench_mode = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			config->strategy = 1;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			config->strategy = 2;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			config->strategy = 3;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			config->strategy = 4;
		else
			break ;
		i++;
	}
	return (i);
}

static int	validate_args(char **argv, int start)
{
	int		i;
	long	args;

	i = start;
	while (argv[i])
	{
		if (is_valid_int(argv[i]) == 0)
			return (write(2, "Error\n", 6), 0);
		args = ft_atol(argv[i]);
		if (args > INT_MAX || args < INT_MIN)
			return (write(2, "Error\n", 6), 0);
		if (has_duplicate(argv, i, start) == 1)
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

static void	build_stack(int argc, char **argv, int start, t_node **stack_a)
{
	t_node	*new;

	while ((argc - 1) >= start)
	{
		new = new_node((int)ft_atol(argv[argc - 1]));
		move_to_top(stack_a, new);
		argc--;
	}
}

static void	bench_count_zero(t_bench	*bench)
{
	if (bench == NULL)
		return ;
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->strategy = 0;
}

static void	route_sorting(t_node **stack_a, t_node **stack_b, t_config config,
		t_bench *bench)
{
	int		size;
	float	disorder;

	bench_count_zero(bench);
	if (config.strategy == 1)
		return (selection_sort(stack_a, stack_b, bench));
	else if (config.strategy == 2)
		return (normalize(stack_a), chunk_sort(stack_a, stack_b, bench));
	else if (config.strategy == 3)
		return (normalize(stack_a), radix_sort(stack_a, stack_b, bench));
	size = stack_size(*stack_a);
	if (size == 2)
		return (sa(stack_a, bench));
	else if (size == 3)
		return (sort_three(stack_a, bench));
	else if (size <= 5)
		return (selection_sort(stack_a, stack_b, bench));
	normalize(stack_a);
	disorder = get_disorder(stack_a);
	if (disorder < 0.2f && size < 20)
		selection_sort(stack_a, stack_b, bench);
	else if (disorder >= 0.2f && disorder < 0.5f)
		chunk_sort(stack_a, stack_b, bench);
	else
		radix_sort(stack_a, stack_b, bench);
}

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
	if (is_sorted(&stack_a) == 1)
		return (free_stack(&stack_a), 0);
	route_sorting(&stack_a, &stack_b, config, &bench);
	if (config.bench_mode == 1)
		benchmark(&bench);
	return (free_stack(&stack_a), 0);
}
