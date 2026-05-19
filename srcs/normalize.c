/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 18:39:45 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/19 19:03:29 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	normalize(t_node **stack)
{
	int		rank;
	t_node	*current;
	t_node	*compare;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		rank = 0;
		compare = *stack;
		while (compare)
		{
			if (current->value > compare->value)
				rank++;
			compare = compare->next;
		}
		current->value = rank;
		current = current->next;
	}
}
