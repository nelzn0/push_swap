/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 11:46:39 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/01 18:50:37 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count = ft_puthex(n / 16, base);
		count = count + ft_puthex(n % 16, base);
	}
	else
	{
		ft_putchar(base[n % 16]);
		count = 1;
	}
	return (count);
}
