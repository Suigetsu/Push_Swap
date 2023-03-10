/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:23:38 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/10 11:56:12 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	int		i;
	int		j;
	int		count;
	int		*integer;
	char	**split;
}				t_data;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

int		errors_handler1(char *args, t_data *data);
int		args_checker(char *str, t_data *data);
void	to_integer(char	*str, t_data *data);
void	check_duplicated(int *arr, t_data *data);

#endif
