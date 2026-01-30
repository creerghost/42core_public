/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:11:37 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/29 12:03:06 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_median(t_list *stack, int len, int *pivot)
{
	int		*arr;
	int		i;

	if (len <= 0 || !stack)
		return (0);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	i = 0;
	while (stack && i < len)
	{
		arr[i++] = stack->content;
		stack = stack->next;
	}
	bubble_sort(arr, i);
	*pivot = arr[i / 2];
	free(arr);
	return (1);
}

int	is_sorted(t_list *stack, int len, int is_ascending)
{
	int	i;

	if (!stack || len <= 1)
		return (1);
	i = 0;
	while (stack->next && i < len - 1)
	{
		if (is_ascending && stack->content
			> stack->next->content)
			return (0);
		if (!is_ascending && stack->content
			< stack->next->content)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}
