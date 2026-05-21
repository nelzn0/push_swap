/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:42:10 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/21 17:19:57 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push_min_to_top(t_node **stack_a, int size, int min_pos)
{
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(stack_a);
			min_pos++;
		}
	}
}

void	selection_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	min_pos;

	if (!*stack_a || !stack_a || !stack_b)
		return ;
	while (*stack_a)
	{
		size = stack_size(*stack_a);
		min_pos = get_min_pos(*stack_a);
		push_min_to_top(stack_a, size, min_pos);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
