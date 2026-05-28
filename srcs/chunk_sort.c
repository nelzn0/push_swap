/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:29:51 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/28 20:52:41 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	re(t_node **stack_a, int chunk_size, int i, int *rotate_count)
{
	(*rotate_count)++;
	if (*rotate_count == stack_size(*stack_a))
	{
		i = i + chunk_size;
		*rotate_count = 0;
	}
	return (i);
}

static void	push_to_b(t_node **stack_a, t_node **stack_b, int chunk_size,
		t_bench *bench)
{
	int	i;
	int	rotate_count;

	i = 0;
	rotate_count = 0;
	while (*stack_a)
	{
		if ((*stack_a)->value <= i)
		{
			pb(stack_a, stack_b, bench);
			if (stack_size(*stack_b) > 2)
				rb(stack_b, bench);
			i++;
			rotate_count = 0;
		}
		else if ((*stack_a)->value <= i + chunk_size)
		{
			pb(stack_a, stack_b, bench);
			i++;
			rotate_count = 0;
		}
		else
			(ra(stack_a, bench), i = re(stack_a, chunk_size, i, &rotate_count));
	}
}

static void	push_to_a(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	max_pos;
	int	size_b;

	while (*stack_b)
	{
		max_pos = get_max_pos(*stack_b);
		size_b = stack_size(*stack_b);
		if (max_pos <= size_b / 2)
		{
			while (max_pos)
			{
				rb(stack_b, bench);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size_b)
			{
				rrb(stack_b, bench);
				max_pos++;
			}
		}
		pa(stack_a, stack_b, bench);
	}
}

void	chunk_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	size;
	int	chunk_size;

	size = stack_size(*stack_a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 35;
	push_to_b(stack_a, stack_b, chunk_size, bench);
	push_to_a(stack_a, stack_b, bench);
}
