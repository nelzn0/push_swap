/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:12:16 by nda-roch          #+#    #+#             */
/*   Updated: 2026/06/02 18:53:25 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	adaptive_route(t_node **stack_a, t_node **stack_b, int size,
			t_bench *bench)
{
	normalize(stack_a);
	if (bench)
		bench->strategy = 3;
	if (bench->disorder < 0.2f && size < 20)
		selection_sort(stack_a, stack_b, bench);
	else if (bench->disorder >= 0.2f && bench->disorder < 0.5f)
		chunk_sort(stack_a, stack_b, bench);
	else
		radix_sort(stack_a, stack_b, bench);
}

void	route_sorting(t_node **stack_a, t_node **stack_b, t_config config,
		t_bench *bench)
{
	int		size;

	bench_count_zero(bench);
	size = stack_size(*stack_a);
	if (bench)
	{
		bench->disorder = get_disorder(stack_a);
		bench->strategy = config.strategy - 1;
	}
	if (size >= 100 && config.strategy == 1)
		config.strategy = 2;
	if (config.strategy == 1)
		return (selection_sort(stack_a, stack_b, bench));
	else if (config.strategy == 2)
		return (normalize(stack_a), chunk_sort(stack_a, stack_b, bench));
	else if (config.strategy == 3)
		return (normalize(stack_a), radix_sort(stack_a, stack_b, bench));
	if (size == 2)
		return (sa(stack_a, bench));
	else if (size == 3)
		return (sort_three(stack_a, bench));
	else if (size <= 5)
		return (sort_five(stack_a, stack_b, bench));
	else
		adaptive_route(stack_a, stack_b, size, bench);
}
