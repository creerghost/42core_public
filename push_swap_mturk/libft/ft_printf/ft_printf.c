/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:59:04 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/15 14:59:06 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	conv_spec_handle(const char c, va_list arguments)
{
	size_t	len;

	len = 0;
	if (c == '%')
		len = ft_putchar_printf('%');
	else if (c == 'c')
		len = ft_putchar_printf(va_arg(arguments, int));
	else if (c == 's')
		len = ft_putstr_printf(va_arg(arguments, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr_printf(va_arg(arguments, int), &len);
	else if (c == 'u')
		ft_putnbr_uns_printf(va_arg(arguments, unsigned int), &len);
	else if (c == 'x')
		ft_putnbr_base_printf((size_t)va_arg(arguments, unsigned int),
			"0123456789abcdef", &len);
	else if (c == 'X')
		ft_putnbr_base_printf((size_t)va_arg(arguments, unsigned int),
			"0123456789ABCDEF", &len);
	else if (c == 'p')
		ft_putptr(va_arg(arguments, void *), &len);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	size_t	len;

	len = 0;
	if (!format)
		return (-1);
	va_start(arguments, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
				break ;
			len += conv_spec_handle(*format, arguments);
		}
		else
			len += (size_t)ft_putchar_printf(*format);
		format++;
	}
	va_end(arguments);
	return (len);
}
