/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tointeger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:02:15 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/10 12:25:19 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_integer(char	*str, t_data *data)
{
	int			i;
	static int	j;

	i = 0;
	data->split = ft_split(str, ' ');
	while (data->split[i])
		data->integer[j++] = ft_atoi(data->split[i++]);
	i = 0;
	while (data->split[i])
		free (data->split[i++]);
	free (data->split);
}

void	check_duplicated(int *arr, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->count)
	{
		j = 0;
		while (j < data->count)
		{
			if (i == j)
				j++;
			if (arr[i] == arr[j])
			{
				free (data->integer);
				ft_printf("Error.\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
	
}