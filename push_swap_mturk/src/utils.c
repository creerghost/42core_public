/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 02:43:37 by vlnikola          #+#    #+#             */
/*   Updated: 2026/02/02 12:06:48 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol_safe(const char *str, long *result)
{
	int		sign;
	long	num;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!*str || (*str < '0' || *str > '9'))
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (0);
		str++;
	}
	*result = num * sign;
	return (1);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	is_sorted(t_stack *stack, int len, int is_ascending)
{
	int	i;

	if (!stack || len <= 1)
		return (1);
	i = 0;
	while (stack->next && i < len - 1)
	{
		if (is_ascending && stack->content
			> stack->next->content)
			return (0);
		if (!is_ascending && stack->content
			< stack->next->content)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

void	handle_error(t_stack **stack, char **args,
		int should_free_args)
{
	ft_putstr_fd("Error\n", 2);
	if (stack && *stack)
		free_stack(stack);
	if (should_free_args && args)
		free_split(args);
	exit(1);
}

void	free_split(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}
