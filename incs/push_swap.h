/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 17:36:40 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/28 21:20:11 by nda-roch         ###   ########.fr       */
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

typedef struct s_bench
{
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		strategy;
	float	disorder;
}	t_bench;

// move printing
void	pa(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	pb(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	sa(t_node **stack, t_bench *bench);
void	sb(t_node **stack, t_bench *bench);
void	ss(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	ra(t_node **stack, t_bench *bench);
void	rb(t_node **stack, t_bench *bench);
void	rr(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	rra(t_node **stack, t_bench *bench);
void	rrb(t_node **stack, t_bench *bench);
void	rrr(t_node **stack_a, t_node **stack_b, t_bench *bench);

// moves
void	push(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	rrotate(t_node **stack);
void	sort_three(t_node **stack_a, t_bench *bench);

// algos
void	selection_sort(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	chunk_sort(t_node **stack_a, t_node **stack_b, t_bench *bench);
void	radix_sort(t_node **stack_a, t_node **stack_b, t_bench *bench);

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

// setup
int		parse_flags(char **argv, t_config *config);
int		validate_args(char **argv, int start);
void	build_stack(int argc, char **argv, int start, t_node **stack_a);

// routing
void	route_sorting(t_node **stack_a, t_node **stack_b, t_config config,
			t_bench *bench);

// get positions
int		get_min_pos(t_node *stack_a);
int		get_max_pos(t_node *stack_b);

// benchmark
void	benchmark(t_bench *bench);

#endif
