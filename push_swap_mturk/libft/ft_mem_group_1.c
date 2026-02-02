/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_group_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:15:58 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/11 01:45:55 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*val;
	size_t			i;

	val = (unsigned char *)s;
	i = 0;
	while (i < n)
		val[i++] = c;
	return (s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*val_dest;
	unsigned char	*val_src;

	val_dest = (unsigned char *)dest;
	val_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		val_dest[i] = val_src[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*val_dest;
	unsigned char	*val_src;

	val_dest = (unsigned char *)dest;
	val_src = (unsigned char *)src;
	if (val_dest == val_src || n == 0)
		return (dest);
	if (val_dest > val_src)
	{
		val_dest += n - 1;
		val_src += n - 1;
		while (n--)
			*val_dest-- = *val_src--;
	}
	else
		while (n--)
			*val_dest++ = *val_src++;
	return (dest);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s_val;

	i = 0;
	s_val = (unsigned char *)s;
	while (i < n)
		s_val[i++] = 0;
}
/*
int	main(int argc, char **argv)
{
	char	*str;

	str = argv[1];
	if (argc != 2)
		return (0);
	printf("%s\n", str);
	ft_bzero(str, atoi(argv[2]));
	printf("%s\n", str);
}*/
/*
int	main(void)
{
  char  src[20] = "HelloWorld";
  char  dest[20];
  ft_memccpy(dest, src, 'r', 10);
  printf("%s", dest);

}*/
/*
int	main(void)
{
	char *str = strdup("ABCDEF");

	ft_memcpy(str + 1, str, 3);
	printf("memcpy: %s\n", str);
	strcpy( str, "ABCDEF");
	ft_memmove(str + 1, str, 3);
	printf("memmove: %s", str);
	free (str);
}
*/
