/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_draft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:53:50 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/29 17:49:06 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	calculate_moves(t_stack **a, t_stack **b, int max)
// {
// 	t_stack	*temp;
// 	int		move;
// 	int		closest_index;
	
// 	temp = *b;
// 	closest_index = find_max_index(b);
// 	while (temp != NULL)
// 	{
// 		if ((*a)->value >= max)
// 			move = (*a)->index + find_max_index(*b);
// 		else if ((*a)->index < temp->index && temp->index <= closest_index)
// 		{
// 			closest_index = temp->index;
// 			move = (*a)->index + closest_index;
// 		}
// 		temp = temp->next;
// 	}
// 	return (move);
// }

// int	find_max(t_stack **head)
// {
// 	t_stack	*temp;
// 	int		max;

// 	temp = *head;
// 	max = INT_MIN;
// 	while (temp != NULL)
// 	{
// 		if (temp->value > max)
// 			max = temp->value;
// 		temp = temp->next;
// 	}
// 	return (max);
// }

int	find_max_index(t_stack **head)
{
	t_stack	*temp;
	int		max;
	int		max_index;
	
	temp = *head;
	max_index = 0;
	max = INT_MIN;
	while (temp != NULL)
	{
		if (temp->value > max)
		{
			max = temp->value;
			max_index = temp->index;
		}
		temp = temp->next;
	}
	return (max_index);
}

// void	the_algo(t_stack **a, t_stack **b)
// {
// 	int	count;
// 	int	i;
// 	int	max;
// 	int	move;

// 	count = 0;
// 	i = 0;
// 	move = 0;
// 	max = find_max(a);
// 	push_b(a, b);
// 	push_b(a, b);
// 	assign_index(b);
// 	while (*b != NULL)
// 	{
// 		if ((*a)->value >= max)
// 			move = (*a)->index + find_max_index(b);
// 		*b = (*b)->next;
// 	}
// }