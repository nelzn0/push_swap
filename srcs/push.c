/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:08:13 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/19 12:49:15 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_push(t_node **stack_a, t_node **stack_b, const char *operation)
{
	if (operation[0] == 'p' && operation[1] == 'a' && operation[2] == '\0')
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
	}
	else if (operation[0] == 'p' && operation[1] == 'b' && operation[2] == '\0')
	{
		push(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	push(t_node **stack_1, t_node **stack_2)
{
	t_node	*node_to_move;

	if (!stack_1 || !*stack_1)
		return ;
	node_to_move = *stack_1;
	*stack_1 = (*stack_1)->next;
	node_to_move->next = *stack_2;
	*stack_2 = node_to_move;
}
