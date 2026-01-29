/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:58:48 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/29 12:02:02 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **a)
{
	long	fst;
	long	snd;
	long	trd;

	fst = (long)(*a)->content;
	snd = (long)(*a)->next->content;
	trd = (long)(*a)->next->next->content;
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

static int	get_min_index(t_list *stack)
{
	int		min;
	int		min_index;
	int		i;
	t_list	*tmp;

	if (!stack)
		return (-1);
	tmp = stack;
	min = (int)(long)tmp->content;
	min_index = 0;
	i = 0;
	while (tmp)
	{
		if ((int)(long)tmp->content < min)
		{
			min = (int)(long)tmp->content;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}

void	sort_five(t_list **a, t_list **b, int size)
{
	int	min_index;
	int	i;
	if (is_sorted(*a, size, 1))
		return ;
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
