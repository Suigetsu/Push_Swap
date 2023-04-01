/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:35:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/01 10:47:05 by mlagrini         ###   ########.fr       */
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
		swap_a_checker(a);
	else if (c == 'p')
		push_a_checker(a, b);
	else if (c == 'r')
		ra_checker(a);
}

static void	b_instructions(char c, t_stack **a, t_stack **b)
{
	if (c == 's')
		swap_b_checker(b);
	else if (c == 'p')
		push_b_checker(a, b);
	else if (c == 'r')
		rb_checker(b);
}

static void	r_instructions(char *str, t_stack **a, t_stack **b)
{
	if (ft_strlen(str) == 3)
	{
		if (str[0] == 'r')
			rr_checker(a, b);
		else
			print_error3(str, a, b);
	}
	else if (ft_strlen(str) == 4)
	{
		if (str[0] == 'r')
		{
			if (str[2] == 'a')
				rra_checker(a);
			else if (str[2] == 'b')
				rrb_checker(b);
			else if (str[2] == 'r')
				rrr_checker(a, b);
			else
				print_error3(str, a, b);
		}
	}
}

void	is_instructions(char *str, t_stack **a, t_stack **b)
{
	if (ft_strlen(str) < 3 || ft_strlen(str) > 4)
		print_error3(str, a, b);
	if (str[0] != 's' && str[0] != 'r' && str[0] != 'p')
		print_error3(str, a, b);
	if (str[1] == 'a')
		a_instructions(str[0], a, b);
	else if (str[1] == 'b')
		b_instructions(str[0], a, b);
	else if (str[1] == 'r')
	{
		if (str[0] == 'r')
			r_instructions(str, a, b);
		else
			print_error3(str, a, b);
	}
	else if (str[1] == 's')
	{
		if (str[0] == 's')
			ss_checker(a, b);
		else
			print_error3(str, a, b);
	}
	else
		print_error3(str, a, b);
}
