/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 15:38:47 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/16 15:38:48 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_printf(char c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_putstr_printf(char *str)
{
	size_t	len;

	if (!str)
		return (ft_putstr_printf("(null)"), 6);
	len = 0;
	while (str[len])
		ft_putchar_printf(str[len++]);
	return (len);
}

void	ft_putnbr_uns_printf(unsigned int n, size_t *len)
{
	if (n >= 10)
		ft_putnbr_uns_printf(n / 10, len);
	ft_putchar_printf(n % 10 + '0');
	(*len)++;
}

void	ft_putnbr_printf(int n, size_t *len)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_printf('-');
		(*len)++;
		nbr = -nbr;
	}
	if (nbr >= 10)
		ft_putnbr_printf(nbr / 10, len);
	ft_putchar_printf(nbr % 10 + '0');
	(*len)++;
}
