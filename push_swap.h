/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:23:38 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/20 13:18:53 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	int		i;
	int		j;
	int		count;
	int		*integer;
	char	**split;
}				t_data;

typedef struct s_stack
{
	int					data;
	struct s_stack		*next;
}				t_stack;

int			errors_handler1(char *args, t_data *data);
int			args_checker(char *str, t_data *data);
void		to_integer(char	*str, t_data *data, t_stack **stack);
void		check_duplicated(t_stack *stack, t_data *data);
void		create_node(t_stack **node, int data);
void 		printList(t_stack *head);
void		push_b(t_stack **a_head, t_stack **b_head);
void		push_a(t_stack **a_head, t_stack **b_head);
void		swap_a(t_stack **a_head);
void		swap_a(t_stack **b_head);
void		ss(t_stack **a_head, t_stack **b_head);
void		ra(t_stack **a_head);
void		rb(t_stack **b_head);
void		rr(t_stack **a_head, t_stack **b_head);
void		rra(t_stack **a_head);
void		rrb(t_stack **b_head);
void		rrr(t_stack **a_head, t_stack **b_head);
void		sort_three(t_stack **a_head);
void		sort_two(t_stack **a_head);
void		sort_four(t_stack **a, t_stack **b);
void		sort_five(t_stack **a, t_stack **b);
int			is_sorted(t_stack *a_head);
int			linkedlen(t_stack *stack_a);
void		sort_four_five(t_stack **a, t_stack **b);


#endif
