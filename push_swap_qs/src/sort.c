/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:44:49 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/24 12:16:12 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	restore_stack(t_stack **stack, int moves_count, int is_a)
{
	int	i;

	if (moves_count == ft_lstsize((t_list *)*stack))
		return ;
	i = 0;
	while (i < moves_count)
	{
		if (is_a)
			rra(stack);
		else
			rrb(stack);
		i++;
	}
}

static int	qsort_base_a(t_stack **a, int len)
{
	if (is_sorted(*a, len, 1))
		return (1);
	if (len == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(*a);
		return (1);
	}
	if (len == 3 && ft_lstsize((t_list *)*a) == 3)
	{
		sort_three(a);
		return (1);
	}
	return (0);
}

static int	qsort_base_b(t_stack **a, t_stack **b, int len)
{
	if (len == 0)
		return (1);
	if (len == 1)
	{
		pa(a, b);
		return (1);
	}
	if (len == 2)
	{
		if ((*b)->value < (*b)->next->value)
			sb(*b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	return (0);
}

int	qsort_a(t_stack **a, t_stack **b, int len)
{
	int	pivot;
	int	moves_count;
	int	i;

	if (qsort_base_a(a, len))
		return (1);
	pivot = get_median(*a, len);
	moves_count = 0;
	i = 0;
	while (i < len)
	{
		if ((int)(long)(*a)->value < pivot)
		{
			pb(a, b);
			moves_count++;
		}
		else
			ra(a);
		i++;
	}
	restore_stack(a, len - moves_count, 1);
	qsort_a(a, b, len - moves_count);
	qsort_b(a, b, moves_count);
	return (1);
}

int	qsort_b(t_stack **a, t_stack **b, int len)
{
	int	pivot;
	int	moves_count;
	int	i;

	if (qsort_base_b(a, b, len))
		return (1);
	pivot = get_median(*b, len);
	moves_count = 0;
	i = 0;
	while (i < len)
	{
		if ((int)(long)(*b)->value >= pivot)
		{
			pa(a, b);
			moves_count++;
		}
		else
			rb(b);
		i++;
	}
	qsort_a(a, b, moves_count);
	restore_stack(b, len - moves_count, 0);
	qsort_b(a, b, len - moves_count);
	return (1);
}
