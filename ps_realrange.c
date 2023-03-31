/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_realrange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 06:57:37 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/30 15:44:07 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	from_a_to_b(t_stack **a, t_stack **b, int count)
{
	int		min_range;
	int		max_range;

	min_range = 0;
	max_range = 14;
	if (count == 500)
		max_range += 15;
	while (linkedlen(*a) > 0)
	{
		if ((*a)->value >= min_range && (*a)->value <= max_range)
		{
			push_b(a, b);
			// if ((*b)->next != NULL && (*b)->value < (*b)->next->value)
			// 	rb(b);
			min_range++;
			max_range++;
		}
		else if ((*a)->value > max_range)
			ra(a);
		else if ((*a)->value < min_range)
		{
			push_b(a, b);
			if ((*b)->next != NULL)
				rb(b);
			min_range++;
			max_range++;
		}
	}
}

static void	from_b_to_a(t_stack **a, t_stack **b)
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

void	algo(t_stack **a, t_stack **b, int count)
{
	from_a_to_b(a, b, count);
	from_b_to_a(a, b);
}