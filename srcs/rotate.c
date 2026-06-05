/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:35:44 by nda-roch          #+#    #+#             */
/*   Updated: 2026/06/05 15:49:37 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack, t_bench *bench)
{
	rotate(stack);
	ft_printf("ra\n");
	bench->ra++;
	bench->total_ops++;
}

void	rb(t_node **stack, t_bench *bench)
{
	rotate(stack);
	ft_printf("rb\n");
	bench->rb++;
	bench->total_ops++;
}

void	rr(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	bench->rr++;
	bench->total_ops++;
}

void	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*current;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	current = *stack;
	head = *stack;
	while (current->next)
	{
		current = current->next;
	}
	*stack = head->next;
	head->next = NULL;
	current->next = head;
}
