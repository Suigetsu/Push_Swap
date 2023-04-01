/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:48:46 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/01 12:25:11 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	printlist(t_stack **a)
{
	while (*a != NULL)
	{
		ft_printf("%d ", (*a)->data);
		*a = (*a)->next;
	}
	ft_printf("\n");
}

void	check_op(t_data *data, t_stack **a, t_stack **b)
{
	is_instructions(data->str, a, b);
	free (data->str);
	data->str = get_next_line(0);
	if (data->str == NULL)
	{
		if (is_sorted(*a) == 0)
		{
			printlist(a);
			free_nodes(a);
			ft_printf("OK\n");
			exit (0);
		}
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	t_stack	init;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_bzero(&init, sizeof(t_stack));
	ft_bzero(&data, sizeof(t_data));
	data.i = 1;
	while (data.i < ac)
		data.count += args_checker(av[data.i++], &data);
	data.i = 1;
	while (data.i < ac)
		to_integer(av[data.i++], &data, &a);
	check_duplicated(a, &data);
	data.str = get_next_line(0);
	while (data.str)
		check_op(&data, &a, &b);
	printlist(&a);
	free_nodes(&a);
	ft_printf("KO\n");
	return (0);
}
