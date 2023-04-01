/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_instruc4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:49:24 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/01 10:45:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate_stack(t_stack **head)
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

void	ra_checker(t_stack **a_head)
{
	if (*a_head == NULL)
		return ;
	rotate_stack(a_head);
}

void	rb_checker(t_stack **b_head)
{
	if (*b_head == NULL)
		return ;
	rotate_stack(b_head);
}

void	rr_checker(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	rotate_stack(a_head);
	rotate_stack(b_head);
}
