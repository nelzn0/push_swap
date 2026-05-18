/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 11:58:12 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/01 19:22:11 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_r(unsigned long n)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count = count + ft_putptr_r(n / 16);
		count = count + ft_putptr_r(n % 16);
	}
	else
	{
		ft_putchar("0123456789abcdef"[n]);
		count = 1;
	}
	return (count);
}

int	ft_putptr(unsigned long n)
{
	int	count;

	count = 0;
	if (!n)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	count = 2;
	count = count + ft_putptr_r(n);
	return (count);
}
