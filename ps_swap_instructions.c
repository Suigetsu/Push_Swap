/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 18:38:07 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/17 11:13:10 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a_head)
{
	t_stack	*temp;

	if (*a_head == NULL || (*a_head)->next == NULL)
		return ;
	temp = (*a_head)->next;
	(*a_head)->next = temp->next;
	temp->next = *a_head;
	*a_head = temp;
	ft_printf("sa\n");
}

void	swap_b(t_stack **b_head)
{
	t_stack	*temp;

	if (*b_head == NULL || (*b_head)->next == NULL)
		return ;
	temp = (*b_head)->next;
	(*b_head)->next = temp->next;
	temp->next = *b_head;
	*b_head = temp;
	ft_printf("sa\n");
}

void	ss(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	swap_a(a_head);
	swap_b(b_head);
	ft_printf("ss\n");
}
