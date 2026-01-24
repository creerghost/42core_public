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

// parser.c
void				parse_args(int argc, char **argv, t_list **stack_a);
// utils.c
void				free_stack(t_list **stack);
int					ft_atol_safe(const char *str, long *result);
// swap.c
void				ss(t_list *stack_a, t_list *stack_b);
void				sb(t_list *stack_b);
void				sa(t_list *stack_a);
// push.c
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
// rotate.c
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
// reverse_rotate.c
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
// sort_utils.c
int					is_sorted(t_list *stack, int len, int is_ascending);
int					get_median(t_list *stack, int len);
void				sort_three(t_list **stack_a);
// sort.c
int					qsort_b(t_list **a, t_list **b, int len);
int					qsort_a(t_list **a, t_list **b, int len);
#endif
