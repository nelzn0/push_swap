/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:35:44 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/19 20:25:26 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rb(t_node **stack)
{
	rotate(stack);
	ft_printf("rb\n");
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
