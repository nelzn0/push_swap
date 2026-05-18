/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 11:25:03 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/01 11:37:01 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count = ft_putnbr_u(n / 10);
		count = count + ft_putnbr_u(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		count = 1;
	}
	return (count);
}
