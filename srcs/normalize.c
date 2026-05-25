/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:39:45 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/25 16:37:23 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize(t_node **stack)
{
	int		rank;
	t_node	*current;
	t_node	*compare;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		rank = 0;
		compare = *stack;
		while (compare)
		{
			if (current->numbers > compare->numbers)
				rank++;
			compare = compare->next;
		}
		current->value = rank;
		current = current->next;
	}
}
