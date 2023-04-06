/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:35:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/06 13:24:26 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_args(t_stack **a, t_stack **b, t_data *data)
{
	if (data->count == 2)
		sort_two(a);
	if (data->count == 3)
		sort_three(a);
	if (data->count > 3 && data->count <= 5)
		sort_four_five(a, b);
	if (data->count > 5)
	{
		if (is_sorted(*a) == 0)
		{
			free_nodes(a);
			exit (0);
		}
		else if (inverted_sorting(a) == 0)
			push_and_rotate(a, b);
		else
			range_algo(a, b, data);
	}
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
	check_duplicated(&a, &data);
	assign_value(&a);
	assign_index(&a);
	sort_args(&a, &b, &data);
	free_nodes(&a);
	return (0);
}
