/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:38:07 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/12 18:45:48 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack_a **head)
{
	t_stack_a	*temp;
	
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	ft_printf("sa\n");
}

void	swap_a(t_stack_b **head)
{
	t_stack_b	*temp;
	
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next = *head;
	*head = temp;
	ft_printf("sa\n");
}

void	ss(t_stack_a **a_head, t_stack_b **b_head)
{
	swap_a(a_head);
	swap_b(b_head);
	ft_printf("ss\n");
}