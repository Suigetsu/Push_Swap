/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:59:41 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/25 14:14:15 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_nodes(t_stack **a)
{
	t_stack *a_temp;

	while (*a != NULL)
	{
		a_temp = *a;
		*a = (*a)->next;
		free(a_temp);
	}
}
