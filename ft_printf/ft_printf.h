/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 00:09:49 by mlagrini          #+#    #+#             */
/*   Updated: 2023/04/06 13:51:54 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_puthex(unsigned int n);
int		ft_putuphex(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_putadrs(unsigned long n);

#endif
