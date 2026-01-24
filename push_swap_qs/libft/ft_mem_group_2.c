/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_group_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:02:29 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/10 10:52:32 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_val;
	unsigned char	c_val;

	s_val = (unsigned char *)s;
	c_val = (unsigned char)c;
	while (n--)
	{
		if (*s_val == c_val)
			return (s_val);
		s_val++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s", ft_memchr("Hello World!", 'l', 2));
}*/
