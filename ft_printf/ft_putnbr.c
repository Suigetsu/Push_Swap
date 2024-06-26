/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:21:23 by mlagrini          #+#    #+#             */
/*   Updated: 2022/10/23 23:53:00 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	countdigit(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		n *= -1;
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int		count;

	count = countdigit(n);
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n >= 0 && n <= 9)
		ft_putchar (n + '0');
	else if (n < 0)
	{
		count++;
		ft_putchar('-');
		ft_putnbr(n *= -1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (count);
}
