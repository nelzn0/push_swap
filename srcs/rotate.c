/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:35:44 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/18 16:02:52 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_rotate(t_node **stack_a, t_node **stack_b, const char *operation)
{
	if (operation[0] == 'r' && operation[1] == 'a' && operation[2] == '\0')
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (operation[0] == 'r' && operation[1] == 'b' && operation[2] == '\0')
	{
		rotate(stack_b);
		ft_printf("rb\n");
	}
	else if (operation[0] == 'r' && operation[1] == 'r' && operation[2] == '\0')
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
	}
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
	current->next = head;
	*stack = head->next;
	head->next = NULL;
}
