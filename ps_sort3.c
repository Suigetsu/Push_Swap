/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:15:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/17 17:04:33 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a_head)
{
	if ((*a_head)->data > (*a_head)->next->data)
		swap_a(a_head);
}

void	sort_three(t_stack **a_head)
{
	if ((*a_head)->data > (*a_head)->next->data && \
		(*a_head)->next->data < (*a_head)->next->next->data && \
		(*a_head)->next->next->data > (*a_head)->data)
		swap_a(a_head);
	else if ((*a_head)->data > (*a_head)->next->data && \
			(*a_head)->next->data > (*a_head)->next->next->data && \
			(*a_head)->next->next->data < (*a_head)->data)
	{
		swap_a(a_head);
		rra(a_head);
	}
	else if ((*a_head)->data > (*a_head)->next->data && \
			(*a_head)->next->data < (*a_head)->next->next->data && \
			(*a_head)->next->next->data < (*a_head)->data)
		ra(a_head);
	else if ((*a_head)->data < (*a_head)->next->data && \
			(*a_head)->next->data > (*a_head)->next->next->data && \
			(*a_head)->next->next->data > (*a_head)->data)
	{
		swap_a(a_head);
		ra(a_head);
	}
	else if ((*a_head)->data < (*a_head)->next->data && \
			(*a_head)->next->data > (*a_head)->next->next->data && \
			(*a_head)->next->next->data < (*a_head)->data)
		rra(a_head);
}