/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:08:20 by vlnikola          #+#    #+#             */
/*   Updated: 2026/02/02 12:18:00 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_value(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest_node;
	t_stack	*ptr;
	int		cheapest_node_value;

	ptr = stack;
	cheapest_node_value = INT_MAX;
	cheapest_node = NULL;
	while (ptr)
	{
		if (abs_value(ptr->cost_a) + abs_value(ptr->cost_b)
			< cheapest_node_value)
		{
			cheapest_node_value = abs_value(ptr->cost_a)
				+ abs_value(ptr->cost_b);
			cheapest_node = ptr;
		}
		ptr = ptr->next;
	}
	return (cheapest_node);
}

void	move_cheapest_node(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*b);
	do_double_rotations(a, b, cheapest_node);
	do_solo_rotations(a, b, cheapest_node);
	pa(a, b);
}
