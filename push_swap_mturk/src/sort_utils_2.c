/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:08:20 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/30 19:26:16 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_double_rotations(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b);
		node->cost_a++;
		node->cost_b++;
	}
}

void	do_solo_rotations(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a != 0)
	{
		if (node->cost_a > 0)
		{
			ra(a);
			node->cost_a--;
		}
		else
		{
			rra(a);
			node->cost_a++;
		}
	}
	while (node->cost_b != 0)
	{
		if (node->cost_b > 0)
		{
			rb(b);
			node->cost_b--;
		}
		else
		{
			rrb(b);
			node->cost_b++;
		}
	}
}

t_stack	*get_cheapest_node(t_stack *b)
{
	t_stack	*res;
	t_stack	*ptr;
	int		res_value;

	ptr = b;
	res_value = INT_MAX;
	res = NULL;
	while (ptr)
	{
		if (abs_val(ptr->cost_a) + abs_val(ptr->cost_b) < res_value)
		{
			res_value = abs_val(ptr->cost_a) + abs_val(ptr->cost_b);
			res = ptr;
		}
		ptr = ptr->next;
	}
	return (res);
}

void	move_cheapest_node(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*b);
	if (!cheapest_node)
		return ;
	do_double_rotations(a, b, cheapest_node);
	do_solo_rotations(a, b, cheapest_node);
	pa(a, b);
}

int abs_val(int n)
{
    if (n < 0)
        return (n * -1);
    return (n);
}