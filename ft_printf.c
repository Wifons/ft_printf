/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wifons <wifons@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:58:30 by wifons            #+#    #+#             */
/*   Updated: 2025/01/14 20:44:31 by wifons           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

static ssize_t process_format(char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (format == 'u')
		return (ft_putnbr((unsigned int)va_arg(args, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int	total_length;

	total_length = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			total_length += process_format(*format, args);
		}
		else
			total_length += ft_putchar(*format);
	}
	va_end(args);
	return (total_length);
}
