/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:39:59 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/16 15:40:02 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_printf(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putnbr_base_printf(size_t n, char *base, size_t *len)
{
	size_t	base_len;

	base_len = ft_strlen_printf(base);
	if (n >= base_len)
		ft_putnbr_base_printf(n / base_len, base, len);
	ft_putchar_printf(base[n % base_len]);
	(*len)++;
}

void	ft_putptr(void *ptr, size_t *len)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (!ptr)
	{
		*len += ft_putstr_printf("(nil)");
		return ;
	}
	*len += ft_putstr_printf("0x");
	ft_putnbr_base_printf((size_t)ptr, hex_base, len);
}
