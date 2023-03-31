/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:35:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/30 15:35:45 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(t_stack **head, int data)
{
	t_stack	*new_node;
	t_stack	*last;

	last = NULL;
	new_node = malloc(sizeof(t_stack));
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

int	main(int ac, char **av)
{
	t_data		data;
	t_stack		*a;
	t_stack		*b;
	t_stack		init;

	a = NULL;
	b = NULL;
	ft_bzero(&init, sizeof(t_stack));
	ft_bzero(&data, sizeof(t_data));
	data.i = 1;
	while (data.i < ac)
		data.count += args_checker(av[data.i++], &data);
	if (ac <= 2 && data.count < 2)
		exit(0);
	data.i = 1;
	while (data.i < ac)
		to_integer(av[data.i++], &data, &a);
	check_duplicated(a, &data);
	assign_value(&a);
	assign_index(&a);
	if (data.count == 2)
		sort_two(&a);
	if (data.count == 3)
		sort_three(&a);
	if (data.count > 3 && data.count <= 5)
		sort_four_five(&a, &b);
	if (data.count > 5)
		algo(&a, &b, data.count);
	free_nodes(&a);
}
