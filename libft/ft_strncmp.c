/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:14:08 by mlagrini          #+#    #+#             */
/*   Updated: 2022/10/15 15:16:04 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((((unsigned char *)s1)[i] || ((unsigned char *)s2)[i])
			&& i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
			return (1);
		else
			return (-1);
	}
	return (0);
}
