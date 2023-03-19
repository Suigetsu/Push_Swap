/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:15:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/19 20:26:50 by mlagrini         ###   ########.fr       */
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

void	sort_four(t_stack **a, t_stack **b)
{
	push_b(a, b);
	sort_three(a);
	push_a(a, b);
	if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->next->next->data \
	&& (*a)->data > (*a)->next->next->next->data)
		ra(a);
	else if ((*a)->data > (*a)->next->data && (*a)->data < (*a)->next->next->data)
		swap_a(a);
	else if ((*a)->data > (*a)->next->data && (*a)->data > (*a)->next->next->data \
	&& (*a)->data < (*a)->next->next->next->data)
	{
		rra(a);
		swap_a(a);
		ra(a);
		ra(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	index;

	index = 0;
	push_b(a, b);
	sort_four(a, b);
	push_a(a, b);
	if ((*a)->data > (*a)->next->data)
		ra(a);
}