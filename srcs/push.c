/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:08:13 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/28 14:14:50 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	push(stack_b, stack_a, bench);
	ft_printf("pa\n");
	bench->pa++;
}

void	pb(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	push(stack_a, stack_b, bench);
	ft_printf("pb\n");
	bench->pb++;
}

void	push(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	t_node	*node_to_move;

	if (!stack_a || !*stack_a)
		return ;
	node_to_move = *stack_a;
	*stack_a = (*stack_a)->next;
	node_to_move->next = *stack_b;
	*stack_b = node_to_move;
	bench->total_ops++;
}
