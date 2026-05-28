/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:03:02 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/28 13:56:29 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack, t_bench *bench)
{
	rrotate(stack);
	ft_printf("rra\n");
	bench->rra++;
	bench->total_ops++;
}

void	rrb(t_node **stack, t_bench *bench)
{
	rrotate(stack);
	ft_printf("rrb\n");
	bench->rrb++;
	bench->total_ops++;
}

void	rrr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
	bench->rrr++;
	bench->total_ops++;
}

void	rrotate(t_node **stack)
{
	t_node	*tail;
	t_node	*current;
	t_node	*head;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	current = *stack;
	head = *stack;
	while (current->next->next)
	{
		current = current->next;
	}
	tail = current->next;
	*stack = tail;
	tail->next = head;
	current->next = NULL;
}
