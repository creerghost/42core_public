/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:11:37 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/24 11:44:41 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i;
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
	return (arr);
}

int	get_median(t_stack *stack, int len)
{
	int		*arr;
	int		i;
	char	res;
	t_stack	*ptr;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (0);
	ptr = stack;
	i = 0;
	while (i < len)
	{
		arr[i++] = (int)(long)ptr->value;
		ptr = ptr->next;
	}
	arr = bubble_sort(arr, len);
	res = arr[len / 2];
	free(arr);
	return (res);
}

int	is_sorted(t_stack *stack, int len, int is_ascending)
{
	int	i;

	i = 0;
	while (stack && stack->next && i < len - 1)
	{
		if (is_ascending && stack->value > stack->next->value)
			return (0);
		if (!is_ascending && stack->value < stack->next->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

void	sort_three(t_stack **stack_a)
{
	long	fst;
	long	snd;
	long	trd;

	fst = (long)(*stack_a)->value;
	snd = (long)(*stack_a)->next->value;
	trd = (long)(*stack_a)->next->next->value;
	if (fst > snd && snd < trd && fst < trd)
		sa(*stack_a);
	else if (fst > snd && snd > trd)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	else if (fst > snd && snd < trd && fst > trd)
		ra(stack_a);
	else if (fst < snd && snd > trd && fst < trd)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	else if (fst < snd && snd > trd && fst > trd)
		rra(stack_a);
}
