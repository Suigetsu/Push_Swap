/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:52:38 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/15 17:18:05 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a_head)
{
	t_stack	*temp;
	t_stack	*last;

	if (*a_head == NULL)
		return ;
	temp = *a_head;
	*a_head = (*a_head)->next;
	last = *a_head;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	ft_printf("ra\n");
}

void	rb(t_stack **b_head)
{
	t_stack	*temp;
	t_stack	*last;

	if (*b_head == NULL)
		return ;
	temp = *b_head;
	*b_head = (*b_head)->next;
	last = *b_head;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	ft_printf("rb\n");
}

void	rr(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	ra(a_head);
	rb(b_head);
	ft_printf("rr\n");
}