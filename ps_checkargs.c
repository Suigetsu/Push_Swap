/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:39:48 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/06 14:03:42 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_error(t_data *data)
{
	int	i;

	i = 0;
	while (data->split[i])
		free (data->split[i++]);
	free (data->split);
	ft_printf("Error.\n");
	exit (1);
}

static void	check_num(char *str, t_data *data)
{
	int			i;
	long long	limit;

	i = 0;
	limit = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		print_error(data);
	while (str[i] >= '0' && str[i] <= '9')
	{
		limit = limit * 10 + str[i] - '0';
		i++;
	}
	if (!(limit <= 2147483647 && limit >= -2147483648))
		print_error(data);
	if (str[i] != '\0')
		print_error(data);
}

int	args_checker(char *str, t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	data->split = ft_split(str, ' ');
	while (data->split[i] != NULL)
	{
		check_num(data->split[i++], data);
		count++;
	}
	i = 0;
	while (data->split[i])
		free (data->split[i++]);
	free (data->split);
	return (count);
}
