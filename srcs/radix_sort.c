/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 17:52:55 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/28 14:08:11 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	int	i;
	int	n;
	int	count;

	i = 0;
	n = stack_size(*stack_a);
	while (((n - 1) >> i) != 0)
	{
		count = 0;
		while (count < n)
		{
			if (((*stack_a)->value & (1 << i)) == 0)
				pb(stack_a, stack_b, bench);
			else
				ra(stack_a, bench);
			count++;
		}
		while (*stack_b)
		{
			pa(stack_a, stack_b, bench);
		}
		i++;
	}
}
