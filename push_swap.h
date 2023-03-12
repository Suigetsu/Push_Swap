/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:23:38 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/12 16:27:15 by mlagrini         ###   ########.fr       */
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

typedef struct s_node
{
	int					*data;
	struct s_node		*next;
}				t_node;


typedef struct s_stack_a
{
	int					data;
	struct s_stack_a	*next;
	struct s_stack_a	*top;
}				t_stack_a;

typedef struct s_stack_b
{
	int					*data;
	struct s_stack_b	*top;
}				t_stack_b;

int			errors_handler1(char *args, t_data *data);
int			args_checker(char *str, t_data *data);
void		to_integer(char	*str, t_data *data, t_stack_a **stack_a);
void		check_duplicated(t_stack_a *stack_a, t_data *data);
void		new_first_node(t_stack_a *top_a, int data);
void		create_node(t_stack_a **node, int data);
void 		printList(t_stack_a *head);

#endif
