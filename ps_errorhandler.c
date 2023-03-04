/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errorhandler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:13:24 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/04 10:24:39 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_array(t_data *data)
{
	free (data->integer);
	ft_printf("Error\n");
	exit (1);
}

static void	nbr_checker(char *str, t_data *data)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		free_array(data);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9') || str[i] == '\0')
		free_array(data);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	if (nbr > 2147483647)
		free_array(data);
	if (str[i] != '\0')
		free_array(data);
}

int	errors_handler1(char *args, t_data *data)
{
	int	nbr;
	int	i;

	nbr_checker(args, data);
	i = 0;
	nbr = ft_atoi(args);
	return (nbr);
}
