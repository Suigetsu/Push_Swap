/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:45:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/30 14:32:47 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void	best_move_algo(t_stack **a, t_stack **b)
// {
// 	int	count;
// 	/* int	len; */

// 	count = 0;
// 	while (is_sorted(*a) && count < 2)
// 	{
// 		push_b(a, b);
// 		count++;
// 	}
// 	if (!is_sorted(*a))
// 	{
// 		if (count == 1 && (*b)->data > (*a)->data)
// 		{
// 			push_a(a, b);
// 			ra(a);
// 		}
// 		else if (count == 2)
// 		{
// 			if (!is_sorted(*b))
// 				swap_b(b);
// 			push_a(a, b);
// 			push_a(a, b);
// 			while (count > 0)
// 			{
// 				if (is_sorted(*a))
// 					ra(a);
// 				count--;
// 			}
// 		}
// 	}
// }
