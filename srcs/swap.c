/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:06:00 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/18 16:11:11 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_swap(t_node **stack_a, t_node **stack_b, const char *operation)
{
	if (operation[0] == 's' && operation[1] == 'a' && operation[2] == '\0')
	{
		swap(stack_a);
		ft_printf("sa\n");
	}
	else if (operation[0] == 's' && operation[1] == 'b' && operation[2] == '\0')
	{
		swap(stack_b);
		ft_printf("sb\n");
	}
	else if (operation[0] == 's' && operation[1] == 's' && operation[2] == '\0')
	{
		swap(stack_a);
		swap(stack_b);
		ft_printf("ss\n");
	}
}

void	swap(t_node **stack)
{
	int	temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}
