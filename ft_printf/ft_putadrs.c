/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:48:53 by mlagrini          #+#    #+#             */
/*   Updated: 2023/03/25 13:39:53 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadrs(unsigned long n)
{
	char	*str;
	int		count;

	count = 0;
	str = "0123456789abcdef";
	if (n > 0 && n <= 15)
		ft_putchar (str[n]);
	else
	{
		ft_putadrs(n / 16);
		ft_putadrs(n % 16);
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
