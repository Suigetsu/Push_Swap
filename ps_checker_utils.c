/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:35:56 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/31 12:02:53 by mlagrini         ###   ########.fr       */
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

void	r_instructions(char *str, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 2)
}

void	is_instructions(char *str, t_stack **a, t_stack **b)
{
	int	i;
	
	i = 0;
	if (s[i] != 's' || s[i] != 'r' || s[i] != 'p')
		print_error3(str, a, b);
	i++;
	if (s[i] == 'a')
		a_instructions(s[0], a, b);
	else if (s[i] == 'b')
		b_instructions(s[0], a, b);
	else if (s[i] == 'r')
	{
		if (s[0] == 'r')
			r_instructions(str, a, b);
		else
			print_error3(str, a, b);
	}
	else
		print_error3(str, a, b);
}