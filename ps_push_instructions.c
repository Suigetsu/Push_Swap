/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:11:26 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/12 18:37:42 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack_b **head, int data)
{
	t_stack_b	*new_node;

	new_node = malloc (sizeof(t_stack_b));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
	ft_printf("pb\n");
}

void	push_a(t_stack_a **head, int data)
{
	t_stack_a	*new_node;

	new_node = malloc (sizeof(t_stack_a));
	new_node->data = data;
	new_node->next = *head;
	*head = new_node;
	ft_printf("pa\n");
}