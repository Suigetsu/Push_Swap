/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:23:38 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/06 12:31:38 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	int		i;
	int		j;
	int		index1;
	int		index2;
	int		count;
	int		*integer;
	int		min_range;
	int		max_range;
	char	**split;
	char	*str;
}				t_data;

typedef struct s_stack
{
	int				index;
	int				value;
	int				data;
	struct s_stack	*next;
}				t_stack;

int		args_checker(char *str, t_data *data);
void	push_b(t_stack **a_head, t_stack **b_head);
void	push_a(t_stack **a_head, t_stack **b_head);
void	rra(t_stack **a_head);
void	rrb(t_stack **b_head);
void	rrr(t_stack **a_head, t_stack **b_head);
void	ra(t_stack **a_head);
void	rb(t_stack **b_head);
void	rr(t_stack **a_head, t_stack **b_head);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four_five(t_stack **a, t_stack **b);
void	range_algo(t_stack **a, t_stack **b, t_data *data);
void	swap_a(t_stack **a_head);
void	swap_b(t_stack **b_head);
void	ss(t_stack **a_head, t_stack **b_head);
void	create_node(t_stack **head, int data);
void	to_integer(char	*str, t_data *data, t_stack **stack_a);
void	check_duplicated(t_stack **stack_a, t_data *data);
int		linkedlen(t_stack *stack_a);
int		is_sorted(t_stack *a_head);
void	assign_index(t_stack **head);
void	assign_value(t_stack **head);
int		find_min(t_stack **a);
int		find_max(t_stack **a);
void	free_nodes(t_stack **a);
void	sort_args(t_stack **a, t_stack **b, t_data *data);
int		inverted_sorting(t_stack **a);
void	push_and_rotate(t_stack **a, t_stack **b);

#endif
