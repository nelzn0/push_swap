/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nda-roch <nda-roch@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:51:30 by nda-roch          #+#    #+#             */
/*   Updated: 2026/05/01 18:56:06 by nda-roch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

// functions
int	ft_putchar(char c);
int	ft_puthex(unsigned int n, char *base);
int	ft_putnbr(int n);
int	ft_putnbr_u(unsigned int n);
int	ft_putptr_r(unsigned long n);
int	ft_putptr(unsigned long n);
int	ft_putstr(char *s);

// functions printf
int	ft_printf(const char *format, ...);
int	ft_conversion(char c, va_list ap);

#endif
