/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sortbig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 06:57:37 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/06 12:32:42 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	inverted_sorting(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next != NULL)
	{
		if (temp->value < temp->next->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	push_and_rotate(t_stack **a, t_stack **b)
{
	while (linkedlen(*a) > 0)
		push_b(a, b);
	while (linkedlen(*b) > 0)
	{
		rrb(b);
		push_a(a, b);
	}
}

void	from_a_to_b(t_stack **a, t_stack **b, t_data *data)
{
	data->min_range = 0;
	data->max_range = 14;
	if (data->count == 500)
		data->max_range += 15;
	while (linkedlen(*a) > 0)
	{
		if ((*a)->value >= data->min_range && (*a)->value <= data->max_range)
		{
			push_b(a, b);
			data->min_range++;
			data->max_range++;
		}
		else if ((*a)->value > data->max_range)
			ra(a);
		else if ((*a)->value < data->max_range)
		{
			push_b(a, b);
			if ((*b)->next != NULL)
				rb(b);
			data->min_range++;
			data->max_range++;
		}
	}
}

void	from_b_to_a(t_stack **a, t_stack **b)
{
	int	max;

	while (linkedlen(*b) > 0)
	{
		max = find_max(b);
		while (max != 0)
		{
			if (max < linkedlen(*b) / 2)
				rb(b);
			else
				rrb(b);
			max = find_max(b);
		}
		push_a(a, b);
	}
}

void	range_algo(t_stack **a, t_stack **b, t_data *data)
{
	from_a_to_b(a, b, data);
	from_b_to_a(a, b);
}
