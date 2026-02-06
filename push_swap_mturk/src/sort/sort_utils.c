/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:11:37 by vlnikola          #+#    #+#             */
/*   Updated: 2026/02/03 13:41:20 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_min_node(t_stack *stack)
{
	int		min_val;
	t_stack	*min_node;

	min_val = INT_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->content < min_val)
		{
			min_val = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	fix_stack(t_stack **a)
{
	t_stack	*min_node;
	int		len;

	min_node = get_min_node(*a);
	len = ft_lstsize_ps(*a);
	while ((*a)->content != min_node->content)
	{
		if (min_node->index <= len / 2)
			ra(a);
		else
			rra(a);
	}
}

void	assign_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize_ps(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->is_above_median = 1;
		else
			stack->is_above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	find_target_node(t_stack *a, t_stack *b)
{
	t_stack	*ptr_a;
	t_stack	*target;
	int		best_value;

	while (b)
	{
		best_value = INT_MAX;
		target = NULL;
		ptr_a = a;
		while (ptr_a)
		{
			if (ptr_a->content > b->content && ptr_a->content < best_value)
			{
				best_value = ptr_a->content;
				target = ptr_a;
			}
			ptr_a = ptr_a->next;
		}
		if (target == NULL)
			target = get_min_node(a);
		b->target_node = target;
		b = b->next;
	}
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize_ps(a);
	len_b = ft_lstsize_ps(b);
	while (b)
	{
		if (b->is_above_median)
			b->cost_b = b->index;
		else
			b->cost_b = (len_b - b->index) * -1;
		if (b->target_node->is_above_median)
			b->cost_a = b->target_node->index;
		else
			b->cost_a = (len_a - b->target_node->index) * -1;
		b = b->next;
	}
}
