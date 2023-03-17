/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:35:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/17 17:05:18 by mlagrini         ###   ########.fr       */
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

void printList(t_stack *head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int	main(int ac, char **av)
{
	t_data		data;
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	ft_bzero(&data, sizeof(t_data));
	if (ac <= 2)
		exit(0);
	data.i = 1;
	while (av[data.i])
		data.count += args_checker(av[data.i++], &data);
	data.i = 1;
	while (av[data.i])
		to_integer(av[data.i++], &data, &a);
	check_duplicated(a, &data);
	if (ac == 3)
		sort_two(&a);
	if (ac == 4)
		sort_three(&a);
	printList(a);
}
