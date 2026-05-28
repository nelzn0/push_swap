/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:11:28 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/28 21:11:43 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_flags(char **argv, t_config *config)
{
	int	i;

	config->strategy = 4;
	config->bench_mode = 0;
	i = 1;
	while (argv[i])
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			config->bench_mode = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			config->strategy = 1;
		else if (ft_strcmp(argv[i], "--medium") == 0)
			config->strategy = 2;
		else if (ft_strcmp(argv[i], "--complex") == 0)
			config->strategy = 3;
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			config->strategy = 4;
		else
			break ;
		i++;
	}
	return (i);
}

int	validate_args(char **argv, int start)
{
	int		i;
	long	args;

	i = start;
	while (argv[i])
	{
		if (is_valid_int(argv[i]) == 0)
			return (write(2, "Error\n", 6), 0);
		args = ft_atol(argv[i]);
		if (args > INT_MAX || args < INT_MIN)
			return (write(2, "Error\n", 6), 0);
		if (has_duplicate(argv, i, start) == 1)
			return (write(2, "Error\n", 6), 0);
		i++;
	}
	return (1);
}

void	build_stack(int argc, char **argv, int start, t_node **stack_a)
{
	t_node	*new;

	while ((argc - 1) >= start)
	{
		new = new_node((int)ft_atol(argv[argc - 1]));
		move_to_top(stack_a, new);
		argc--;
	}
}
