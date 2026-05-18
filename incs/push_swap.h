/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:36:40 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/18 16:30:23 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define <unistd.h>
# define <stddef.h>
# define <stdlib.h>

typedef struct t_node
{
	int **stack;
} 	t_node;

// move handling
void	handle_push(t_node **stack_a, t_node **stack_b, const char *operation);
void	handle_swap(t_node **stack_a, t_node **stack_b, const char *operation);
void	handle_rotate(t_node **stack_a, t_node **stack_b, const char *operation);
void	handle_rrotate(t_node **stack_a, t_node **stack_b, const char *operation);

// moves
void	push(t_node **stack_1, t_node **stack_2);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	rrotate(t_node **stack);

// disorder
float	find_disorder(t_node **stack);

#endif
