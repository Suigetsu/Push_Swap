/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:48:46 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/31 14:45:49 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_stack	init;
	t_stack	*a;
	t_stack	*b;
	int		fd;

	a = NULL;
	b = NULL;
	fd = 0;
	ft_bzero(&init, sizeof(t_stack));
	ft_bzero(&data, sizeof(t_data));
	data.i = 1;
	while (data.i < ac)
		data.count += args_checker(av[data.i++], &data);
	data.i = 1;
	while (data.i < ac)
		to_integer(av[data.i++], &data, &a);
	check_duplicated(a, &data);
	assign_value(&a);
	assign_index(&a);
	while (fd != EOF)
	{
		data.str = get_next_line(fd);
		is_instructions(data.str, &a, &b);
	}
}