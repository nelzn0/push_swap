/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 18:24:42 by nda-roch          #+#    #+#             */
/*   Updated: 2026/06/02 18:56:17 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push_min_to_top(t_node **stack_a, int size, int min_pos,
		t_bench *bench)
{
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, bench);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(stack_a, bench);
			min_pos++;
		}
	}
}

void	sort_five(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	size;
	int	min_pos;

	if (!*stack_a || !stack_a || !stack_b)
		return ;
	while (stack_size(*stack_a) > 3)
	{
		size = stack_size(*stack_a);
		min_pos = get_min_pos(*stack_a);
		push_min_to_top(stack_a, size, min_pos, bench);
		pb(stack_a, stack_b, bench);
	}
	sort_three(stack_a, bench);
	while (*stack_b)
	{
		pa(stack_a, stack_b, bench);
	}
}
