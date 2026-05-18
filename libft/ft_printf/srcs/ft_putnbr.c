/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 11:21:26 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/01 19:24:26 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		count++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		count = count + ft_putnbr(nb / 10);
		count = count + ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
		count = count + 1;
	}
	return (count);
}
