/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:39:43 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/27 10:05:03 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_nbr(int element, t_stack **head)
{
	int	len;
	int	index;
	t_stack	*temp;

	len = linkedlen(*head);
	index = 0;
	temp = *head;
	while (temp != NULL)
	{
		if (element == temp->data)
			return (index);
		index++;
		temp = temp->next;
	}
	return (-1);
}
