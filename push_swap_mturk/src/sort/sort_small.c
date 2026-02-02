/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:58:48 by vlnikola          #+#    #+#             */
/*   Updated: 2026/02/02 12:31:07 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	fst;
	int	snd;
	int	trd;

	fst = (*a)->content;
	snd = (*a)->next->content;
	trd = (*a)->next->next->content;
	if (fst > snd && snd < trd && fst < trd)
		sa(*a);
	else if (fst > snd && snd > trd)
	{
		sa(*a);
		rra(a);
	}
	else if (fst > snd && snd < trd && fst > trd)
		ra(a);
	else if (fst < snd && snd > trd && fst < trd)
	{
		sa(*a);
		ra(a);
	}
	else if (fst < snd && snd > trd && fst > trd)
		rra(a);
}

static int	get_min_index(t_stack *stack)
{
	int		min;
	int		res;
	int		i;

	min = INT_MAX;
	res = 0;
	i = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			res = i;
		}
		stack = stack->next;
		i++;
	}
	return (res);
}

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int	min_index;
	int	i;

	while (size > 3)
	{
		min_index = get_min_index(*a);
		if (min_index <= size / 2)
		{
			i = 0;
			while (i++ < min_index)
				ra(a);
		}
		else
		{
			i = 0;
			while (i++ < size - min_index)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
