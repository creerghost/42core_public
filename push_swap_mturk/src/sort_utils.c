/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 11:11:37 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/30 19:25:55 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    fix_stack(t_stack **a)
{
    t_stack *min_node;
    int     len;

    min_node = find_min_node(*a);
    len = ft_lstsize_ps(*a);

    while ((*a)->content != min_node->content)
    {
        if (min_node->index <= len / 2)
            ra(a);
        else
            rra(a);
    }
}

void assign_index(t_stack *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return;
    median = ft_lstsize_ps(stack) / 2;
    while (stack)
    {
        stack->index = i;
        
        if (i <= median)
            stack->is_above_median = 1;
        else
            stack->is_above_median = 0;

        stack = stack->next;
        i++;
    }
}

t_stack *find_min_node(t_stack *stack)
{
    int     min_val;
    t_stack *min_node;

    if (!stack)
        return (NULL);
    min_val = INT_MAX;
    min_node = NULL;
    while (stack)
    {
        if (stack->content < min_val)
        {
            min_val = stack->content;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

void find_target_node(t_stack *a, t_stack *b)
{
    t_stack *curr_a;
    t_stack *target;
    int		best_value;

    while (b)
    {
        best_value = INT_MAX;
        target = NULL;
        curr_a = a;

        while (curr_a)
        {
            if (curr_a->content > b->content && curr_a->content < best_value)
            {
                best_value = curr_a->content;
                target = curr_a;
            }
            curr_a = curr_a->next;
        }

        if (target == NULL)
            target = find_min_node(a);
        b->target_node = target;
        b = b->next;
    }
}

void calculate_cost(t_stack *a, t_stack *b)
{
    int len_a;
    int len_b;

    len_a = ft_lstsize_ps(a);
    len_b = ft_lstsize_ps(b);

    while (b)
    {
        if (b->is_above_median)
			b->cost_b = b->index;
		else
            b->cost_b = (len_b - b->index) * -1;
        if (b->target_node->is_above_median)
            b->cost_a = b->target_node->index;
        else
            b->cost_a = (len_a - b->target_node->index) * -1;
        b = b->next;
    }
}