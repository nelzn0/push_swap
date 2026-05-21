/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:56:38 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/21 17:21:28 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_min_pos(t_node *stack_a)
{
	t_node	*ptr;
	int		min_pos;
	int		min;
	int		current_pos;

	if (!stack_a)
		return (0);
	ptr = stack_a;
	min_pos = 0;
	current_pos = 0;
	min = stack_a->value;
	while (ptr)
	{
		if (ptr->value < min)
		{
			min = ptr->value;
			min_pos = current_pos;
		}
		current_pos++;
		ptr = ptr->next;
	}
	return (min_pos);
}
