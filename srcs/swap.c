/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:06:00 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/19 20:51:44 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_node **stack)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
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
