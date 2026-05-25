/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:36:40 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/25 16:40:38 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				numbers;
	struct s_node	*next;
}	t_node;

typedef struct s_config
{
	int	strategy;
	int	bench_mode;
}	t_config;

// move printing
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack);
void	sb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);

// moves
void	push(t_node **stack_a, t_node **stack_b);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	rrotate(t_node **stack);
void	sort_three(t_node **stack_a);

// algos
void	selection_sort(t_node **stack_a, t_node **stack_b);
void	chunk_sort(t_node **stack_a, t_node **stack_b);
void	radix_sort(t_node **stack_a, t_node **stack_b);

// disorder
float	get_disorder(t_node **stack);

// normalization
void	normalize(t_node **stack);

// utils
long	ft_atol(char *str);
int		is_sorted(t_node **stack);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
int		ft_strcmp(char *s1, char *s2);

// node management
t_node	*new_node(int arg_numbers);
void	move_to_top(t_node **arr, t_node *new);

// parse
int		is_valid_int(char *str);
int		has_duplicate(char **argv, int i, int start);

// get positions
int		get_min_pos(t_node *stack_a);
int		get_max_pos(t_node *stack_b);

#endif
