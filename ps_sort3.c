/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:15:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/25 13:36:35 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack **a)
{
	t_stack	*temp;
	int		pos;
	int		i;
	int		best_min;

	temp = *a;
	pos = 0;
	i = 0;
	best_min = INT_MAX;
	while (temp)
	{
		if (temp->data < best_min)
		{
			best_min = temp->data;
			pos = i;
		}
		i++;
		temp = temp->next;
	}
	return (pos);
}

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
