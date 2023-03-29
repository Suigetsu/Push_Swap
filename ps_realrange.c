/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_realrange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 06:57:37 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/29 18:16:00 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_a_to_b(t_stack **a, t_stack **b)
{
	int		min_range;
	int		max_range;
	// t_stack	*temp;

	min_range = 1;
	max_range = 15;
	// temp = *a;
	// ft_printf("this is value %d\n", (*a)->value);
	while (linkedlen(*a) > 0)
	{
		if ((*a)->value >= min_range && (*a)->value <= max_range)
		{
			push_b(a, b);
			// if ((*b)->next != NULL && (*b)->value < (*b)->next->value)
			// 	rb(b);
			min_range++;
			max_range++;
			// *a = (*a)->next;
		}
		else if ((*a)->value > max_range)
			ra(a);
		else if ((*a)->value < min_range)
		{
			push_b(a, b);
			rb(b);
			min_range++;
			max_range++;
			// *a = (*a)->next;
		}
		// *a = (*a)->next;
	}
}

// void	from_b_to_a(t_stack **a, t_stack **b)
// {
// 	int	max_index;
	
// 	(void)a;
// 	max_index = find_max_index(b);
// 	ft_printf("\nthe index = %d, %d\n", max_index, (*b)->value);
// 	while (linkedlen(*b) > 0)
// 	{
// 		max_index = find_max_index(b);
// 		if ((*b)->value != max_index)
// 		{
// 			if (max_index < linkedlen(*b) / 2)
// 			{
// 				// while ((*b)->value != max_index)
// 					rb(b);
// 				// ft_printf("\nthe index = %d\n", max_index);
// 			}
// 			else
// 			{
// 				// while ((*b)->value != max_index)
// 					rrb(b);
// 				// ft_printf("\nlen %d\n", linkedlen(*b));
// 				// ft_printf("\nthe index = %d, %d\n", max_index, (*b)->value);
// 			}
// 			// max_index = find_max_index(b);
// 		}
// 		push_a(a, b);
// 	}
// }

// void	from_b_to_a(t_stack **a, t_stack **b)
// {
// 	int	max_value;
// 	int i = 1;
	
// 	while (i < linkedlen(*b))
// 	{
// 		max_value = find_max(b);
// 		if ((*b)->value != max_value)
// 		{
// 			if (max_value < linkedlen(*b) / 2)
// 			{
// 				while ((*b)->value != max_value)
// 					rb(b);
// 			}
// 			else
// 			{
// 				while ((*b)->value != max_value)
// 					rrb(b);
// 			}
// 		}
// 		push_a(a, b);
// 		i++;
// 	}
// }

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

// void	sort_a(t_stack **a)
// {
// 	if (is_sorted(*a))
// 		return ;
// 	while (!is_sorted(*a))
// 	{
// 		while (find_min(a) != 0)
// 		{
// 			if (find_min(a) < linkedlen(*a) / 2)
// 				ra(a);
// 			else
// 				rra(a);
// 		}
// 	}
// }

void	algo(t_stack **a, t_stack **b)
{
	from_a_to_b(a, b);
	from_b_to_a(a, b);
	// sort_a(a);
}