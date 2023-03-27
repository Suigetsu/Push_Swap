/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate_instructions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:07:13 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/27 07:53:15 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack **head)
{
	t_stack	*last;
	t_stack	*new_last;

	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = *head;
	*head = last;
	new_last = *head;
	while (new_last->next != last)
		new_last = new_last->next;
	new_last->next = NULL;
}

void	rra(t_stack **a_head)
{
	if (*a_head == NULL)
		return ;
	rev_rotate_stack(a_head);
	ft_printf("rra\n");
}

void	rrb(t_stack **b_head)
{
	if (*b_head == NULL)
		return ;
	rev_rotate_stack(b_head);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a_head, t_stack **b_head)
{
	if (*a_head == NULL || *b_head == NULL)
		return ;
	rev_rotate_stack(a_head);
	rev_rotate_stack(b_head);
	ft_printf("rrr\n");
}
