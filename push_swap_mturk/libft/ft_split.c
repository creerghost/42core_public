/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 08:05:57 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/10 09:13:18 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
			continue ;
		}
		s++;
	}
	return (count);
}

static char	*fill_word(const char *s, char c)
{
	size_t	len;
	char	*res;
	char	*ptr;

	len = 0;
	while (s[len] && (s[len] != c))
		len++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ptr = res;
	while (len--)
		*ptr++ = *s++;
	*ptr = 0;
	return (res);
}

static void	free_all(char **res, size_t i)
{
	while (i > 0)
		free(res[i--]);
	free(res);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			res[i] = fill_word(s, c);
			if (!res[i])
				return (free_all(res, i), NULL);
			i++;
			while (*s && (*s != c))
				s++;
		}
	}
	res[i] = NULL;
	return (res);
}
/*
int	main(int argc, char **argv)
{
	int	i = 0;
	char	**res = ft_split(argv[1], argv[2][0]);
	while (i < count_words(argv[1], argv[2][0]))
		printf("%s\n", res[i++]);
	free_all(res, count_words(argv[1], argv[2][0]));
}*/
