/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fniteri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:59:30 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/10 10:52:42 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;
	size_t	s_len;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen(s);
	res = (char *)malloc(s_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
char fcn(unsigned int i, char c)
{
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return c - 32;  // Convert to uppercase
    return c;
}

int main(void)
{
    char *str = "hello world!";
    char *result;

    result = ft_strmapi(str, fcn);
    if (result)
    {
        printf("Original: %s\n", str);
        printf("Modified: %s\n", result);
        free(result); // Don't forget to free allocated memory
    }
    return 0;
}

#include <stdio.h>

void to_upper_even(unsigned int i, char *c)
{
    if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
        *c = *c - 32;  // convert to uppercase
}

int main(void)
{
    char str[] = "hello world";

    ft_striteri(str, to_upper_even);
    printf("%s\n", str);  // Prints: HeLlO WoRlD

    return 0;
}*/
