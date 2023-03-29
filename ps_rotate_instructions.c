/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:52:38 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/29 18:03:08 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack **head)
{
	t_stack	*temp;
	t_stack	*last;

	temp = *head;
	*head = (*head)->next;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	last->next->next = NULL;
}

void	ra(t_stack **a_head)
{
	if (*a_head == NULL)
		return ;
	rotate_stack(a_head);
	ft_printf("ra\n");
}

void	rb(t_stack **b_head)
{
	if (*b_head == NULL)
		return ;
	rotate_stack(b_head);
	ft_printf("rb\n");
}

void	rr(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	rotate_stack(a_head);
	rotate_stack(b_head);
	ft_printf("rr\n");
}
