/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:38:07 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/29 18:06:19 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack **head)
{
	t_stack	*temp;

	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
}

void	swap_a(t_stack **a_head)
{
	if (*a_head == NULL || (*a_head)->next == NULL)
		return ;
	swap_stack(a_head);
	ft_printf("sa\n");
}

void	swap_b(t_stack **b_head)
{
	if (*b_head == NULL || (*b_head)->next == NULL)
		return ;
	swap_stack(b_head);
	ft_printf("sb\n");
}

void	ss(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	swap_stack(a_head);
	swap_stack(b_head);
	ft_printf("ss\n");
}
