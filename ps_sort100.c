/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:45:14 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/21 17:38:31 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_top_moves(t_stack **b_head, int index)
{
	int	len;
	int moves_nbr;
	int	i;

	i = 0;
	moves_nbr = 0;
	len = linkedlen(*b_head);
	if (i > len / 2)
	{
		while (i < len)
		{
			rrb(b_head);
			moves_nbr++;
			i++;
		}
		return (moves_nbr);
	}
	else
	{
		while (i > 0)
		{
			rb(b_head);
			moves_nbr++;
			i--;
		}
		return (moves_nbr);
	}
	return (0);
}

void	sort_one_o_o(t_stack **a, t_stack **b)
{
	int	len;
	int	min;

	len = linkedlen(*a);
	while (len > 2)
	{
		push_b(a, b);
		len--;
	}
	if ()
}