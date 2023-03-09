/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:35:18 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/09 16:50:59 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ac <= 2)
		exit(0);
	data.i = 1;
	while (av[data.i])
		data.count += args_checker(av[data.i++], &data);
	data.integer = ft_calloc(data.count + 1, sizeof(int));
	data.i = 1;
	while (av[data.i])
		to_integer(av[data.i++], &data);
	while (data.integer[data.j])
		ft_printf("%d\n", data.integer[data.j++]);
}
