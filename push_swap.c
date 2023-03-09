/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:01:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/07 21:38:50 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (ac <= 2)
		exit (0);
	while (av[++data.i])
		data.count++;
	data.i = 1;
	data.integer = ft_calloc(data.count + 1, sizeof(int));
	while (av[data.i])
	{
		errors_handler1(av, &data);
		data.i++;
		data.j++;
	}
	data.j = 0;
	while (data.j < data.count)
		ft_printf("%d\n", data.integer[data.j++]);
	return (0);
}
