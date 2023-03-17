/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tointeger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:02:15 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/17 16:08:38 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_error2(t_data *data)
{
	free (data->integer);
	ft_printf("Error.\n");
	exit (1);
}

// void	from_linked_to_arr(t_stack *a, char t_data *data)
// {
	
// }

void	check_duplicated(t_stack *stack_a, t_data *data)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = linkedlen(stack_a);
	data->integer = ft_calloc(len + 1, sizeof(int));
	while (stack_a != NULL)
	{
		data->integer[i++] = stack_a->data;
		stack_a = stack_a->next;
	}
	i = 0;
	while (i < data->count)
	{
		j = 0;
		while (j < data->count)
		{
			if (i == j)
				j++;
			if (data->integer[i] == data->integer[j])
				print_error2(data);
			j++;
		}
		i++;
	}
	free (data->integer);
}