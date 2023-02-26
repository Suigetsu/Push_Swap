/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:01:11 by mlagrini          #+#    #+#             */
/*   Updated: 2023/02/26 11:40:43 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;
	int	j;

	(void)ac;
	i = 0;
	j = 0;
	while (av[i])
		errors_handler1(av[i++]);
	ft_printf("all good \n");
	return (0);
}
