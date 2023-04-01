/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_instruc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:52:06 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/01 10:46:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_b_checker(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;

	if (*a_head == NULL)
		return ;
	temp = *a_head;
	*a_head = (*a_head)->next;
	temp->next = *b_head;
	*b_head = temp;
}

void	push_a_checker(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;

	if (*b_head == NULL)
		return ;
	temp = *b_head;
	*b_head = (*b_head)->next;
	temp->next = *a_head;
	*a_head = temp;
}
