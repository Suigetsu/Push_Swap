/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:35:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/31 16:32:28 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	print_error3(char *str, t_stack **a, t_stack **b)
{
	free(str);
	ft_printf("Error.\n");
	if (*b != NULL)
		free_nodes(b);
	free_nodes(a);
	exit(1);
}

static void	a_instructions(char c, t_stack **a, t_stack **b)
{
	if (c == 's')
		swap_a(a);
	else if (c == 'p')
		push_a(a, b);
	else if (c == 'r')
		ra(a);
}

static void	b_instructions(char c, t_stack **a, t_stack **b)
{
	if (c == 's')
		swap_b(b);
	else if (c == 'p')
		push_b(a, b);
	else if (c == 'r')
		rb(b);
}

static void	r_instructions(char *str, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 2)
	{
		if (str[0] == 'r')
			rr(a, b);
		else
			print_error3(str, a, b);
	}
	else if (ft_strlen(str) == 3)
	{
		if (str[0] == 'r')
		{
			if (str[2] == 'a')
				rra(a);
			else if (str[2] == 'b')
				rrb(b);
			else if (str[2] == 'r')
				rrr(a, b);
			else
				print_error3(str, a, b);
		}
	}
}

void	is_instructions(char *str, t_stack **a, t_stack **b)
{
	int	i;
	
	i = 0;
	ft_printf("%d\n", ft_strlen(str));
	if (ft_strlen(str) < 3 || ft_strlen(str) > 4)
		print_error3(str, a, b);
	if (str[0] != 's' || str[0] != 'r' || str[0] != 'p')
		print_error3(str, a, b);
	i++;
	if (str[i] == 'a')
		a_instructions(str[0], a, b);
	else if (str[i] == 'b')
		b_instructions(str[0], a, b);
	else if (str[i] == 'r')
	{
		if (str[0] == 'r')
			r_instructions(str, a, b);
		else
			print_error3(str, a, b);
	}
	else
		print_error3(str, a, b);
}