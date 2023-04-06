/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tointeger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:02:15 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/06 14:03:32 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error2(t_data *data, t_stack **a)
{
	free_nodes(a);
	free (data->integer);
	ft_printf("Error.\n");
	exit (1);
}

void	create_node(t_stack **head, int data)
{
	t_stack	*new_node;
	t_stack	*last;

	last = NULL;
	new_node = malloc (sizeof(t_stack) + 1);
	new_node->data = data;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void	to_integer(char	*str, t_data *data, t_stack **stack_a)
{
	int	i;

	i = 0;
	data->split = ft_split(str, ' ');
	while (data->split[i])
		create_node(stack_a, ft_atoi(data->split[i++]));
	i = 0;
	while (data->split[i])
		free (data->split[i++]);
	free (data->split);
}

void	check_duplicated(t_stack **stack_a, t_data *data)
{
	t_stack	*temp;

	temp = *stack_a;
	data->integer = ft_calloc((linkedlen(*stack_a) + 1), sizeof(int));
	while (temp != NULL)
	{
		data->integer[data->index1++] = temp->data;
		temp = temp->next;
	}
	data->index1 = 0;
	while (data->index1 < data->count)
	{
		data->index2 = 0;
		while (data->index2 < data->count)
		{
			if (data->index1 == data->index2)
				data->index2++;
			if (data->integer[data->index1] == data->integer[data->index2]
				&& data->index2 < data->count)
				print_error2(data, stack_a);
			data->index2++;
		}
		data->index1++;
	}
	free (data->integer);
}
