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

/* Debug for showing stacks
void	print_stack(t_stack *stack, char *name)
{
	ft_printf("Stack %s:\n", name);
	if (!stack)
	{
		ft_printf("  (empty)\n");
		return ;
	}
	while (stack)
	{
		ft_printf("  value: [%d]\n", (int)(long)stack->value);
		stack = stack->next;
	}
}
*/
static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize((t_list *)*stack_a);
	if (size == 2)
		sa(*stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		qsort_a(stack_a, stack_b, size);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (-1);
	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
