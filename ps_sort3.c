/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:15:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/18 13:28:16 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
}

void	sort_three(t_stack **a)
{
	if ((*a)->data > (*a)->next->data && (*a)->next->data < \
	(*a)->next->next->data && (*a)->next->next->data > (*a)->data)
		swap_a(a);
	else if ((*a)->data > (*a)->next->data && (*a)->next->data > \
	(*a)->next->next->data && (*a)->next->next->data < (*a)->data)
	{
		swap_a(a);
		rra(a);
	}
	else if ((*a)->data > (*a)->next->data && (*a)->next->data < \
	(*a)->next->next->data && (*a)->next->next->data < (*a)->data)
		ra(a);
	else if ((*a)->data < (*a)->next->data && (*a)->next->data > \
	(*a)->next->next->data && (*a)->next->next->data > (*a)->data)
	{
		swap_a(a);
		ra(a);
	}
	else if ((*a)->data < (*a)->next->data && (*a)->next->data > \
	(*a)->next->next->data && (*a)->next->next->data < (*a)->data)
		rra(a);
}
