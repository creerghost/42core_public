/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 02:43:25 by vlnikola          #+#    #+#             */
/*   Updated: 2025/11/23 02:43:26 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

static int	check_duplicate(t_list *stack, int num)
{
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	process_args(char **args, t_list **stack)
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
		ft_lstadd_back(stack, ft_lstnew(num));
		i++;
	}
	return (1);
}

void	handle_error(t_list **stack, char **args,
		int should_free_args)
{
	ft_putstr_fd("Error\n", 2);
	if (stack && *stack)
		free_stack(stack);
	if (should_free_args && args)
		free_split(args);
	exit(1);
}

void	parse_args(int argc, char **argv, t_list **stack)
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
