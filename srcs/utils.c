/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:46:14 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/21 20:23:15 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		sym;
	long	n;

	sym = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sym = -sym;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (sym * n);
}

int	is_sorted(t_node **stack)
{
	t_node	*pos0;
	t_node	*pos1;

	if (!stack || !*stack || !(*stack)->next)
		return (1);
	pos0 = *stack;
	while (pos0)
	{
		pos1 = pos0->next;
		if (!pos1)
			break ;
		if (pos0->value > pos1->value)
			return (0);
		pos0 = pos0->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

int	stack_size(t_node **stack)
{
	int		count;
	t_node	*current;

	count = 0;
	if (!stack || !*stack)
		return (0);
	current = *stack;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (s1 - s2);
}
