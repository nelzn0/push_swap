/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:46:26 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/28 13:46:42 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putfloat_fd(float num)
{
	int	total;
	int	decimal;
	int	point;

	if (num == 0.0f)
	{
		ft_putstr("0.00");
		return ;
	}
	total = (int)(num * 10000.0f + 0.5f);
	decimal = total / 100;
	point = total % 100;
	ft_putnbr(decimal);
	ft_putchar('.');
	ft_putnbr(point);
}

void	benchmark(t_bench *bench)
{
	char	*strategies[4];

	if (!bench || bench->strategy < 0 || bench->strategy > 3)
		return ;
	strategies[0] = "Strategy: --adaptive\nDisorder: ";
	strategies[1] = "Strategy: --simple\nDisorder: ";
	strategies[2] = "Strategy: --medium\nDisorder: ";
	strategies[3] = "Strategy: --complex\nDisorder: ";
	ft_putstr(strategies[bench->strategy]);
	ft_putfloat_fd(bench->disorder);
	ft_printf("%\n");
	ft_printf("Total ops: %i\n", bench->total_ops);
	ft_printf("sa: %i sb: %i ss: %i pa: %i pb: %i\n", bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("ra: %i rb: %i rr: %i rra: %i rrb: %i rrr: %i\n", bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}
