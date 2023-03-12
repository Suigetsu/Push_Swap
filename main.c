/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:35:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/12 16:33:57 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(t_stack_a **node, int data)
{
	t_stack_a	*new_node;
	t_stack_a	*last;

	last = NULL;
	new_node = malloc(sizeof(t_stack_a));
	new_node->data = data;
	new_node->next = NULL;
	if (*node == NULL)
	{
		*node = new_node;
		return ;
	}
	last = *node;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void printList(t_stack_a *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int	main(int ac, char **av)
{
	t_data		data;
	t_stack_a	*a;

	a = NULL;
	ft_bzero(&data, sizeof(t_data));
	if (ac <= 2)
		exit(0);
	data.i = 1;
	while (av[data.i])
		data.count += args_checker(av[data.i++], &data);
	data.integer = ft_calloc(data.count + 1, sizeof(int));
	data.i = 1;
	while (av[data.i])
		to_integer(av[data.i++], &data, &a);
	check_duplicated(a, &data);
	printList(a);
}
