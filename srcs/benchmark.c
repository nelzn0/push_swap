/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:46:26 by side-oli          #+#    #+#             */
/*   Updated: 2026/06/05 15:48:11 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putfloat_fd(float num, int fd)
{
	int	total;
	int	decimal;
	int	point;

	if (num == 0.0f)
	{
		ft_putstr_fd("0.00", 2);
		return ;
	}
	total = (int)(num * 10000.0f + 0.5f);
	decimal = total / 100;
	point = total % 100;
	ft_putnbr_fd(decimal, fd);
	write(fd, ".", 1);
	ft_putnbr_fd(point, fd);
}

static void	print_adaptive_complexity(t_bench *bench)
{
	if (bench->disorder < 0.2f && bench->strategy == 3)
		ft_putstr_fd(" / (O(n^2)", 2);
	else if (bench->disorder >= 0.2f && bench->disorder <= 0.5f
		&& bench->strategy == 3)
		ft_putstr_fd(" / (O(n√n)", 2);
	else if (bench->disorder >= 0.5f && bench->strategy == 3)
		ft_putstr_fd(" / (O(nlog n)", 2);
}

static void	print_label_nbr(char *label, int nbr)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(nbr, 2);
}

void	benchmark(t_bench *bench)
{
	char	*strategies[4];

	if (!bench || bench->strategy < 0 || bench->strategy > 3)
		return ;
	strategies[0] = "%\n[bench] Strategy: --simple / O(n^2)";
	strategies[1] = "%\n[bench] Strategy: --medium / O(n√n)";
	strategies[2] = "%\n[bench] Strategy: --complex / O(n log n)";
	strategies[3] = "%\n[bench] Strategy: --adaptive";
	ft_putstr_fd("\n[bench] Disorder: ", 2);
	ft_putfloat_fd(bench->disorder, 2);
	ft_putstr_fd(strategies[bench->strategy], 2);
	print_adaptive_complexity(bench);
	print_label_nbr("\n[bench] total_ops: ", bench->total_ops);
	print_label_nbr("\n[bench] sa: ", bench->sa);
	print_label_nbr(" sb: ", bench->sb);
	print_label_nbr(" ss: ", bench->ss);
	print_label_nbr(" pa: ", bench->pa);
	print_label_nbr(" pb: ", bench->pb);
	print_label_nbr("\n[bench] ra: ", bench->ra);
	print_label_nbr(" rb: ", bench->rb);
	print_label_nbr(" rr: ", bench->rr);
	print_label_nbr(" rra: ", bench->rra);
	print_label_nbr(" rrb: ", bench->rrb);
	print_label_nbr(" rrr: ", bench->rrr);
	ft_putstr_fd("\n", 2);
}
