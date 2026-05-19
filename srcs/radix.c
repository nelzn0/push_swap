/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:18:46 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/19 20:38:38 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	n;
	int	count;

	i = 0;
	n = stack_size(stack_a);
	while ((1 << i) <= n)
	{
		count = 0;
		while (count < n)
		{
			if (((*stack_a)->value & (1 << i)) != 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			count++;
		}
		while (*stack_b)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}
