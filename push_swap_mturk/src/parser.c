/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 02:43:25 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/30 19:21:41 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	process_args(char **args, t_stack **stack)
{
	long	num;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!ft_atol_safe(args[i], &num))
			return (0);
		if (check_duplicate(*stack, (int)num))
			return (0);
		ft_lstadd_back_ps(stack, ft_lstnew_ps(num));
		i++;
	}
	return (1);
}

void	parse_args(int argc, char **argv, t_stack **stack)
{
	char	**splitted_args;

	if (argc == 2)
	{
		splitted_args = ft_split(argv[1], ' ');
		if (!splitted_args)
			exit(1);
		if (!splitted_args[0])
			handle_error(stack, splitted_args, 1);
		if (!process_args(splitted_args, stack))
			handle_error(stack, splitted_args, 1);
		free_split(splitted_args);
	}
	else
	{
		if (!process_args(argv + 1, stack))
			handle_error(stack, NULL, 0);
	}
}
