/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:11:17 by vlnikola          #+#    #+#             */
/*   Updated: 2026/02/02 12:18:23 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_double_rotations(t_stack **a, t_stack **b,
		t_stack *cheapest_node)
{
	while (cheapest_node->cost_a > 0 && cheapest_node->cost_b > 0)
	{
		rr(a, b);
		cheapest_node->cost_a--;
		cheapest_node->cost_b--;
	}
	while (cheapest_node->cost_a < 0 && cheapest_node->cost_b < 0)
	{
		rrr(a, b);
		cheapest_node->cost_a++;
		cheapest_node->cost_b++;
	}
}

static void	rotate_a(t_stack **a, t_stack *cheapest_node)
{
	while (cheapest_node->cost_a != 0)
	{
		if (cheapest_node->cost_a > 0)
		{
			ra(a);
			cheapest_node->cost_a--;
		}
		else
		{
			rra(a);
			cheapest_node->cost_a++;
		}
	}
}

static void	rotate_b(t_stack **b, t_stack *cheapest_node)
{
	while (cheapest_node->cost_b != 0)
	{
		if (cheapest_node->cost_b > 0)
		{
			rb(b);
			cheapest_node->cost_b--;
		}
		else
		{
			rrb(b);
			cheapest_node->cost_b++;
		}
	}
}

void	do_solo_rotations(t_stack **a, t_stack **b,
		t_stack *cheapest_node)
{
	rotate_a(a, cheapest_node);
	rotate_b(b, cheapest_node);
}
