/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:50:05 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/01 10:55:04 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "gnl/get_next_line.h"
# include "push_swap.h"

void	is_instructions(char *str, t_stack **a, t_stack **b);
void	push_b_checker(t_stack **a_head, t_stack **b_head);
void	push_a_checker(t_stack **a_head, t_stack **b_head);
void	swap_a_checker(t_stack **a_head);
void	swap_b_checker(t_stack **b_head);
void	ss_checker(t_stack **a_head, t_stack **b_head);
void	rra_checker(t_stack **a_head);
void	rrb_checker(t_stack **b_head);
void	rrr_checker(t_stack **a_head, t_stack **b_head);
void	ra_checker(t_stack **a_head);
void	rb_checker(t_stack **b_head);
void	rr_checker(t_stack **a_head, t_stack **b_head);
void	check_op(t_data *data, t_stack **a, t_stack **b);

#endif