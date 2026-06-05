/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:06:00 by side-oli          #+#    #+#             */
/*   Updated: 2026/06/05 15:49:08 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack, t_bench *bench)
{
	swap(stack);
	ft_printf("sa\n");
	bench->sa++;
	bench->total_ops++;
}

void	sb(t_node **stack, t_bench *bench)
{
	swap(stack);
	ft_printf("sb\n");
	bench->sb++;
	bench->total_ops++;
}

void	ss(t_node **stack_a, t_node **stack_b, t_bench *bench)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
	bench->ss++;
	bench->total_ops++;
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
