/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate_instructions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:07:13 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/17 11:12:37 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a_head)
{
	t_stack	*last;
	t_stack	*before_last;

	if (*a_head == NULL)
		return ;
	last = *a_head;
	while (last->next != NULL)
		last = last->next;
	last->next = *a_head;
	*a_head = last;
	before_last = *a_head;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_stack **b_head)
{
	t_stack	*last;
	t_stack	*before_last;

	if (*b_head == NULL)
		return ;
	last = *b_head;
	while (last->next != NULL)
		last = last->next;
	last->next = *b_head;
	*b_head = last;
	before_last = *b_head;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	ft_printf("rrb\n");
}

void	rrr(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	rra(a_head);
	rrb(b_head);
	ft_printf("rrr\n");
}
