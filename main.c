/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:35:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/29 18:17:49 by mlagrini         ###   ########.fr       */
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

// void	printlist(t_stack *head)
// {
// 	while (head != NULL)
// 	{
// 		// printf("%d, %d, %d\n", head->data, head->value, head->index);
// 		printf("%d\n", head->value);
// 		head = head->next;
// 	}
// }

// void    print_stacks(t_stack *s1, t_stack *s2)
// {
//     t_stack    *temp1;
//     t_stack    *temp2;
//     int        height1;
//     int        height2;
//     int        i;

//     temp1 = s1;
//     temp2 = s2;
//     height1 = linkedlen(s1);
//     height2 = linkedlen(s2);
//     i = (height1 > height2) ? height1 : height2;
//     while (i >= 1)
//     {
//         if (i <= height1)
//         {
//             ft_printf("|\t%d\t|", temp1->data);
//             temp1 = temp1->next;
//         }
//         else
//             ft_printf("|\t \t|");
//         if (i <= height2)
//         {
//             ft_printf("|\t%d\t|", temp2->data);
//             temp2 = temp2->next;
//         }
//         else
//             ft_printf("|\t \t|");
//         ft_printf("      ");
//         ft_printf("\n");
//         i--;
//     }
//     ft_printf("\033[0;36m""|\tA\t||\tB\t|\n""\033[0;37m");
// }

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
	// print_stacks(a, b);
	// printf("\n");
	if (data.count == 2)
		sort_two(&a);
	if (data.count == 3)
		sort_three(&a);
	if (data.count > 3 && data.count <= 5)
		sort_four_five(&a, &b);
	if (data.count > 5)
		algo(&a, &b);
	// printf("\n");
	// printf("\n");
	// print_stacks(a, b);
	// 	best_move_algo(&a, &b);

	free_nodes(&a);
	// printlist(a);
}
