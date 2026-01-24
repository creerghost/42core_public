/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 02:45:04 by vlnikola          #+#    #+#             */
/*   Updated: 2026/01/24 12:16:15 by vlnikola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdint.h>

typedef struct s_stack
{
	void			*value;
	int				index;
	struct s_stack	*next;
}					t_stack;
// parser.c
void				parse_args(int argc, char **argv, t_stack **stack_a);
// utils.c
void				free_stack(t_stack **stack);
int					ft_atol_safe(const char *str, long *result);
t_stack				*ft_lstnew_ps(int content);
t_stack				*ft_lstlast_ps(t_stack *lst);
void				ft_lstadd_back_ps(t_stack **lst, t_stack *new);
// swap.c
void				ss(t_stack *stack_a, t_stack *stack_b);
void				sb(t_stack *stack_b);
void				sa(t_stack *stack_a);
// push.c
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
// rotate.c
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
// reverse_rotate.c
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
// sort_utils.c
int					is_sorted(t_stack *stack, int len, int is_ascending);
int					get_median(t_stack *stack, int len);
void				sort_three(t_stack **stack_a);
// sort.c
int					qsort_b(t_stack **a, t_stack **b, int len);
int					qsort_a(t_stack **a, t_stack **b, int len);
#endif
