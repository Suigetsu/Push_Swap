/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:48:46 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/03 09:06:14 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	if_str_null(t_data *data, t_stack **a)
{
	data->str = get_next_line(0);
	if (data->str == NULL)
	{
		if (is_sorted(*a) == 1)
		{
			free_nodes(a);
			ft_printf("KO\n");
			exit(1);
		}
		else
		{
			free_nodes(a);
			ft_printf("OK\n");
			exit(0);
		}
	}
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
			free_nodes(a);
			ft_printf("OK\n");
			exit (0);
		}
		else
		{
			free_nodes(a);
			ft_printf("KO\n");
			exit(1);
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
	if (data.count < 1)
		exit(0);
	data.i = 1;
	while (data.i < ac)
		to_integer(av[data.i++], &data, &a);
	check_duplicated(&a, &data);
	assign_value(&a);
	if_str_null(&data, &a);
	while (data.str)
		check_op(&data, &a, &b);
	free_nodes(&a);
	return (0);
}
