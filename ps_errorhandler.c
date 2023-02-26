/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errorhandler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:13:24 by mlagrini          #+#    #+#             */
/*   Updated: 2023/02/26 11:41:28 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errors_handler1(char *args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_isdigit(args[i]) == 0 || args[i] != ' ')
			exit (1);
		i++;
	}
}