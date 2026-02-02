/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <vlnikola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 02:45:04 by vlnikola          #+#    #+#             */
/*   Updated: 2026/02/02 12:17:34 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdint.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				cost_a;
	int				cost_b;
	int				is_above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
}			t_stack;

// parser.c
void	parse_args(int argc, char **argv, t_stack **stack);
// utils.c
void	free_stack(t_stack **stack);
int		ft_atol_safe(const char *str, long *result);
void	handle_error(t_stack **stack, char **args,
			int should_free_args);
int		is_sorted(t_stack *stack, int len, int is_ascending);
void	free_split(char **args);
// swap.c
void	ss(t_stack *stack_a, t_stack *stack_b);
void	sb(t_stack *stack_b);
void	sa(t_stack *stack_a);
// push.c
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
// rotate.c
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
// reverse_rotate.c
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
// sort_utils.c
void	calculate_cost(t_stack *a, t_stack *b);
void	find_target_node(t_stack *a, t_stack *b);
void	assign_index(t_stack *stack);
void	fix_stack(t_stack **a);
//sort_move_node.c
void	move_cheapest_node(t_stack **a, t_stack **b);
void	do_double_rotations(t_stack **a, t_stack **b,
			t_stack *cheapest_node);
void	do_solo_rotations(t_stack **a, t_stack **b,
			t_stack *cheapest_node);
// sort_small.c
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **a, t_stack **b, int size);
// sort.c
void	sort(t_stack **a, t_stack **b);
void	sort_b(t_stack **a, t_stack **b);
// lists.c
t_stack	*ft_lstnew_ps(int content);
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new);
int		ft_lstsize_ps(t_stack *lst);
t_stack	*ft_lstlast_ps(t_stack *lst);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
#endif
