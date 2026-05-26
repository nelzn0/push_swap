/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 19:21:01 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/26 19:20:49 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int arg_numbers)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->numbers = arg_numbers;
	new->value = 0;
	new->next = NULL;
	return (new);
}

void	move_to_top(t_node **arr, t_node *new)
{
	if (new == NULL || arr == NULL)
		return ;
	new->next = *arr;
	*arr = new;
}
