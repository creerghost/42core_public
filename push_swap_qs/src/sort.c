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

static void	restore_stack(t_list **stack, int items_pushed, int is_a)
{
	int	i;

	if (items_pushed == ft_lstsize(*stack))
		return ;
	i = 0;
	while (i < items_pushed)
	{
		if (is_a)
			rra(stack);
		else
			rrb(stack);
		i++;
	}
}

static int	qsort_base_a(t_list **a, int len)
{
	if (is_sorted(*a, len, 1))
		return (1);
	if (len == 2)
	{
		if ((int)(long)(*a)->content > (int)(long)(*a)->next->content)
			sa(*a);
		return (1);
	}
	if (len == 3 && ft_lstsize(*a) == 3)
	{
		sort_three(a);
		return (1);
	}
	return (0);
}

static int	qsort_base_b(t_list **a, t_list **b, int len)
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
		if ((int)(long)(*b)->content < (int)(long)(*b)->next->content)
			sb(*b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	return (0);
}

int	qsort_a(t_list **a, t_list **b, int len)
{
	int	pivot;
	int	items_pushed;
	int	i;

	if (qsort_base_a(a, len))
		return (1);
	pivot = get_median(*a, len);
	items_pushed = 0;
	i = 0;
	while (i < len)
	{
		if ((int)(long)(*a)->content < pivot)
		{
			pb(a, b);
			items_pushed++;
		}
		else
			ra(a);
		i++;
	}
	if (len != ft_lstsize(*a))
		restore_stack(a, len - items_pushed, 1);
	qsort_a(a, b, len - items_pushed);
	qsort_b(a, b, items_pushed);
	return (1);
}

int	qsort_b(t_list **a, t_list **b, int len)
{
	int	pivot;
	int	items_pushed;
	int	i;

	if (qsort_base_b(a, b, len))
		return (1);
	pivot = get_median(*b, len);
	items_pushed = 0;
	i = 0;
	while (i < len)
	{
		if ((int)(long)(*b)->content >= pivot)
		{
			pa(a, b);
			items_pushed++;
		}
		else
			rb(b);
		i++;
	}
	qsort_a(a, b, items_pushed);
	restore_stack(b, len - items_pushed, 0);
	qsort_b(a, b, len - items_pushed);
	return (1);
}
