/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:56:38 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/26 19:16:09 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_node *stack_a)
{
	t_node	*ptr;
	int		min_pos;
	int		min;
	int		current_pos;

	if (!stack_a)
		return (0);
	ptr = stack_a;
	min_pos = 0;
	current_pos = 0;
	min = stack_a->numbers;
	while (ptr)
	{
		if (ptr->numbers < min)
		{
			min = ptr->numbers;
			min_pos = current_pos;
		}
		current_pos++;
		ptr = ptr->next;
	}
	return (min_pos);
}

int	get_max_pos(t_node *stack_b)
{
	int	max_rank;
	int	max_pos;
	int	current_pos;

	max_rank = stack_b->numbers;
	max_pos = 0;
	current_pos = 0;
	if (!stack_b)
		return (0);
	while (stack_b)
	{
		if (stack_b->numbers > max_rank)
		{
			max_rank = stack_b->numbers;
			max_pos = current_pos;
		}
		current_pos++;
		stack_b = stack_b->next;
	}
	return (max_pos);
}
