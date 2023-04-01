/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_instruc2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:38:00 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/01 09:38:50 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	swap_stack(t_stack **head)
{
	t_stack	*temp;

	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
}

void	swap_a_checker(t_stack **a_head)
{
	if (*a_head == NULL || (*a_head)->next == NULL)
		return ;
	swap_stack(a_head);
}

void	swap_b_checker(t_stack **b_head)
{
	if (*b_head == NULL || (*b_head)->next == NULL)
		return ;
	swap_stack(b_head);
}

void	ss_checker(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	swap_stack(a_head);
	swap_stack(b_head);
}
