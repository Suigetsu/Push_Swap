/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:25:50 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/30 14:28:27 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist(t_stack *head)
{
	while (head != NULL)
	{
		// printf("%d, %d, %d\n", head->data, head->value, head->index);
		printf("%d\n", head->value);
		head = head->next;
	}
}

void    print_stacks(t_stack *s1, t_stack *s2)
{
    t_stack    *temp1;
    t_stack    *temp2;
    int        height1;
    int        height2;
    int        i;

    temp1 = s1;
    temp2 = s2;
    height1 = linkedlen(s1);
    height2 = linkedlen(s2);
    i = (height1 > height2) ? height1 : height2;
    while (i >= 1)
    {
        if (i <= height1)
        {
            ft_printf("|\t%d\t|", temp1->data);
            temp1 = temp1->next;
        }
        else
            ft_printf("|\t \t|");
        if (i <= height2)
        {
            ft_printf("|\t%d\t|", temp2->data);
            temp2 = temp2->next;
        }
        else
            ft_printf("|\t \t|");
        ft_printf("      ");
        ft_printf("\n");
        i--;
    }
    ft_printf("\033[0;36m""|\tA\t||\tB\t|\n""\033[0;37m");
}