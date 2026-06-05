/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_disorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 18:32:47 by side-oli          #+#    #+#             */
/*   Updated: 2026/06/05 15:48:15 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	get_disorder(t_node **stack)
{
	size_t	mistakes;
	size_t	pairs;
	t_node	*pair_pos0;
	t_node	*pair_pos1;

	if (!stack || !*stack || !(*stack)->next)
		return (0.0f);
	mistakes = 0;
	pairs = 0;
	pair_pos0 = *stack;
	while (pair_pos0 != NULL)
	{
		pair_pos1 = pair_pos0->next;
		while (pair_pos1 != NULL)
		{
			pairs++;
			if (pair_pos0->numbers > pair_pos1->numbers)
				mistakes++;
			pair_pos1 = pair_pos1->next;
		}
		pair_pos0 = pair_pos0->next;
	}
	return ((float)mistakes / pairs);
}
