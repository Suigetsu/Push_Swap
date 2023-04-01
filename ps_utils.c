/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:00:09 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/01 11:48:51 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	linkedlen(t_stack *stack_a)
{
	int	len;

	len = 0;
	while (stack_a != NULL)
	{
		stack_a = stack_a->next;
		len++;
	}
	return (len);
}

int	is_sorted(t_stack *a_head)
{
	t_stack	*temp;

	temp = a_head;
	while (temp->next != NULL)
	{
		if (temp->data > temp->next->data \
			|| (temp->data < temp->next->data \
				&& (temp->next->data - temp->data != 1)))
			return (1);
		temp = temp->next;
	}
	return (0);
}

static int	*sort_arr(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
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
	arr = ft_calloc(linkedlen(*head), (sizeof(int) + 1));
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
	free (arr);
}
