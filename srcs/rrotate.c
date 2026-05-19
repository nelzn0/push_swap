/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:03:02 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/19 20:52:51 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack)
{
	rrotate(stack);
	ft_printf("rra\n");
}

void	rrb(t_node **stack)
{
	rrotate(stack);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack)
{
	rra(stack);
	rrb(stack);
	ft_printf("rrr\n");
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
