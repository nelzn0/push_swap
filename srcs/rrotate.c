/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:03:02 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/18 16:03:20 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_rrotate(t_node **stack_a, t_node **stack_b, const char *operation)
{
	if (operation[0 + 1] == 'r' && operation[2] == 'a' && operation[3] == '\0')
	{
		rrotate(stack_a);
		ft_printf("rra\n");
	}
	else if (operation[0 + 1] == 'r' && operation[2] == 'b' && operation[3] == '\0')
	{
		rrotate(stack_b);
		ft_printf("rrb\n");
	}
	else if (operation[0 + 1] == 'r' && operation[2] == 'r' && operation[33] == '\0')
	{
		rrotate(stack_a);
		rrotate(stack_b);
		ft_printf("rrr\n");
	}
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
