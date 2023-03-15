/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:11:26 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/13 16:40:38 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;

	if (*a_head == NULL)
		return ;
	temp = *a_head;
	*a_head = (*a_head)->next;
	temp->next = *b_head;
	*b_head = temp;
	ft_printf("pb\n");
}

void	push_a(t_stack **a_head, t_stack **b_head)
{
	t_stack	*temp;
	
	if (*b_head == NULL)
		return ;
	temp = *b_head;
	*b_head = (*b_head)->next;
	temp->next = *a_head;
	*a_head = temp;
	ft_printf("pa\n");
}