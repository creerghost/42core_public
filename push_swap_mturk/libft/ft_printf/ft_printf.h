/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:51:20 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/16 16:17:28 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
//utils_1.c
size_t	ft_strlen_printf(char *str);
size_t	ft_putchar_printf(char c);
size_t	ft_putstr_printf(char *str);
void	ft_putnbr_uns_printf(unsigned int n, size_t *len);
void	ft_putnbr_printf(int n, size_t *len);
// utils_2.c
void	ft_putnbr_base_printf(size_t n, char *base, size_t *len);
void	ft_putptr(void *ptr, size_t *len);

#endif
