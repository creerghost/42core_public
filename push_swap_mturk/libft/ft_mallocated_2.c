/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocated_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:55:44 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/10 10:52:11 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	set_match(char c, const char *set)
{
	size_t	j;

	j = 0;
	while (set[j])
		if (c == set[j++])
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && set_match(s1[start], set))
		start++;
	while (end > start && set_match(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}
/*
int	main(void)
{
	char *res = ft_strtrim("__Hello!__", "__");
	printf("%s", res);
	free(res);
}
*/
