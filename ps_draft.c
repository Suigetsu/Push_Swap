/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_draft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 06:39:12 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/27 14:18:54 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sort_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	assign_index(t_stack **head)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = *head;
	while (temp != NULL)
	{
		temp->index = index++;
		temp = temp->next;
	}
}

void	assign_value(t_stack **head)
{
	t_stack	*temp;
	int		*arr;
	int		i;

	i = 0;
	arr = (int *)malloc(linkedlen(*head) * sizeof(int) + 1);
	temp = *head;
	while (temp != NULL)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	arr = sort_arr(arr, linkedlen(*head));
	temp = *head;
	while (temp != NULL)
	{
		i = 0;
		while (arr[i] != temp->data)
			i++;
		temp->value = i;
		temp = temp->next;
	}
}