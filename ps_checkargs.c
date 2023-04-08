/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:39:48 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/08 13:51:49 by mlagrini         ###   ########.fr       */
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

	i = 0;
	data->limit = 0;
	data->sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i - 1] == '-')
		data->sign *= -1;
	if (!(str[i] >= '0' && str[i] <= '9'))
		print_error(data);
	while (str[i] >= '0' && str[i] <= '9')
	{
		data->limit = data->limit * 10 + str[i] - '0';
		i++;
	}
	data->limit *= data->sign;
	if (data->limit > INT_MAX || data->limit < INT_MIN)
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
