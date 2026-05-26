/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:50:21 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/26 19:55:20 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*stack_a)->numbers;
	mid = (*stack_a)->next->numbers;
	bot = (*stack_a)->next->next->numbers;
	if (top > mid && mid > bot)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (top > mid && bot > top)
		sa(stack_a);
	else if (top > mid && mid < bot)
		ra(stack_a);
	else if (top < mid && top > bot)
		rra(stack_a);
	else if (top < mid && mid > bot)
	{
		sa(stack_a);
		ra(stack_a);
	}
}
