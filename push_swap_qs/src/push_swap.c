/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 11:13:04 by vlnikola          #+#    #+#             */
/*   Updated: 2025/12/28 11:13:15 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_list(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
	{
		if ((int)(long)(*stack_a)->content > (int)(long)(*stack_a)
			->next->content)
			sa(*stack_a);
	}
	else if (size == 3)
		sort_three(stack_a);
	else
		qsort_a(stack_a, stack_b, size);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	sort_list(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
