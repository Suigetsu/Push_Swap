/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_range100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:45:41 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/28 13:15:12 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_stack(t_stack **a)
{
	t_stack	*temp;
	int		range;
	int		to_top;
	int		to_top2;
	int		small_value;
	
	temp = *a;
	to_top = 0;
	to_top = 0;
	small_value = INT_MAX;
	while (temp != NULL)
	{
		if (temp->index / (linkedlen(*a) / 2) == 0)
		{
			if (temp->value >= 0 && temp->value <= 15 && temp->value < small_value)
			{
				small_value = temp->value;
				to_top = temp->index;
			}
		}
		else if (temp->index / (linkedlen(*a) / 2) > 0)
		{
			if (temp->value >= 0 && temp->value <= 15 && temp->value < small_value)  
		}
		temp = temp->next;
	}
}