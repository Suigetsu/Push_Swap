/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_instruc3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:40:55 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/01 10:45:36 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rev_rotate_stack(t_stack **head)
{
	t_stack	*last;
	t_stack	*new_last;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	*head = last;
	new_last = *head;
	while (new_last->next != last)
		new_last = new_last->next;
	new_last->next = NULL;
}

void	rra_checker(t_stack **a_head)
{
	if (*a_head == NULL)
		return ;
	rev_rotate_stack(a_head);
}

void	rrb_checker(t_stack **b_head)
{
	if (*b_head == NULL)
		return ;
	rev_rotate_stack(b_head);
}

void	rrr_checker(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	rev_rotate_stack(a_head);
	rev_rotate_stack(b_head);
}
