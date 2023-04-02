/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:10:51 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/02 09:06:30 by mlagrini         ###   ########.fr       */
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

int	find_max(t_stack **a)
{
	t_stack	*temp;
	int		pos;
	int		i;
	int		best_min;

	temp = *a;
	pos = 0;
	i = 0;
	best_min = INT_MIN;
	while (temp)
	{
		if (temp->data > best_min)
		{
			best_min = temp->data;
			pos = i;
		}
		i++;
		temp = temp->next;
	}
	return (pos);
}

void	free_nodes(t_stack **a)
{
	t_stack	*a_temp;

	while (*a != NULL)
	{
		a_temp = *a;
		*a = (*a)->next;
		free(a_temp);
	}
}
