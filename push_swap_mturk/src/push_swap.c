/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:13:04 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/30 19:26:25 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sa(*stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b, size);
	else
		sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size_a;

	if (argc < 2)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	size_a = ft_lstsize_ps(stack_a);
	if (!is_sorted(stack_a, size_a, 1))
		sort_stack(&stack_a, &stack_b, size_a);
	free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	return (0);
}
