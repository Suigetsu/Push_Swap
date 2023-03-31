/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3to5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:15:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/31 08:09:23 by mlagrini         ###   ########.fr       */
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

void	sort_four_five(t_stack **a, t_stack **b)
{
	int	len;
	int	min;
	int	j;

	len = linkedlen(*a);
	j = len;
	while (len > 3)
	{
		min = find_min(a);
		while (min != 0)
		{
			if (min < j / 2)
				ra(a);
			else
				rra(a);
			min = find_min(a);
		}
		if (is_sorted(*a))
			push_b(a, b);
		len--;
	}
	sort_three(a);
	push_a(a, b);
	push_a(a, b);
}
