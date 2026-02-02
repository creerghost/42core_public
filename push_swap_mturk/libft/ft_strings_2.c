/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:50:45 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/11 01:47:22 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s) + 1;
	while (len--)
		if (s[len] == (char)c)
			return ((char *)(&(s[len])));
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*big_temp;
	const char	*little_temp;
	size_t		len_temp;

	if (*little == 0)
		return ((char *)big);
	if (big == NULL && len == 0)
		return (NULL);
	while (*big && len--)
	{
		big_temp = big;
		little_temp = little;
		len_temp = len + 1;
		while (*big_temp && *little_temp && len_temp--
			&& *big_temp == *little_temp)
		{
			big_temp++;
			little_temp++;
		}
		if (*little_temp == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s", ft_strnstr("Hello", "ll", 10));
}*/
