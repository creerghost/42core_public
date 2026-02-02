/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:44:49 by vlnikola          #+#    #+#             */
/*   Updated: 2026/02/02 12:07:03 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_stack **a, t_stack **b)
{
	while (*b)
	{
		assign_index(*a);
		assign_index(*b);
		find_target_node(*a, *b);
		calculate_cost(*a, *b);
		move_cheapest_node(a, b);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_lstsize_ps(*a);
	while (len_a > 3)
	{
		pb(a, b);
		len_a--;
	}
	sort_three(a);
	sort_b(a, b);
	fix_stack(a);
}
