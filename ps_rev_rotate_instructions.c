/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate_instructions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:07:13 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/29 18:02:42 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_stack(t_stack **head)
{
	t_stack	*last;
	t_stack	*new_last;

	if (*head == NULL || (*head)->next == NULL)
        return;
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

// void	rev_rotate_stack(t_stack **a_head)
// {
// 	t_stack	*last;
// 	t_stack	*before_last;
	

// 	last = *a_head;
// 	while (last->next != NULL)
// 		last = last->next;
// 	last->next = *a_head;
// 	*a_head = last;
// 	before_last = *a_head;
// 	while (before_last->next != last)
// 		before_last = before_last->next;
// 	before_last->next = NULL;
// }

// void	rev_rotate_stack(t_stack **head)
// {
// 	t_stack *current = *head;
//     t_stack *prev = NULL;
//     t_stack *next = NULL;
    
//     // find the last node in the list
//     while (current->next != NULL) {
//         prev = current;
//         current = current->next;
//     }
    
//     // make the last node the first node
//     next = *head;
//     *head = current;
//     current->next = next;
    
//     // make the second to last node the last node
//     prev->next = NULL;
//     current = *head;
//     while (current->next != NULL) {
//         current = current->next;
//     }
//     current->next = prev;
// }

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
