/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:58:37 by mlagrini          #+#    #+#             */
/*   Updated: 2022/11/18 12:51:55 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*readnsave(int fd, char *holder)
{
	char	*buff;
	int		count;

	buff = malloc (BUFFER_SIZE + 1);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free (holder);
			free (buff);
			return (NULL);
		}
		buff[count] = '\0';
		holder = ft_strjoin(holder, buff);
		if (ft_isnewline(buff))
			break ;
	}
	free (buff);
	return (holder);
}

char	*readline(char *buff)
{
	char	*line;
	int		index;

	index = 0;
	if (buff[index] == '\0')
		return (NULL);
	while (buff[index] != '\0' && buff[index] != '\n')
		index++;
	if (buff[index] == '\n')
	{
		line = ft_substr(buff, 0, (index + 2));
		line[index] = '\n';
		line[index + 1] = '\0';
	}
	else
	{
		line = ft_substr(buff, 0, (index + 1));
		line[index] = '\0';
	}
	return (line);
}

char	*newline(char *buff)
{
	char	*newholder;
	int		index;

	index = 0;
	while (buff[index] != '\0' && buff[index] != '\n')
		index++;
	if (buff[index] == '\0')
	{
		free (buff);
		return (NULL);
	}
	newholder = ft_substr(buff, (index + 1), (ft_strlen(buff) - index + 1));
	free (buff);
	return (newholder);
}

char	*get_next_line(int fd)
{
	static char	*holder[OPEN_MAX];
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = readnsave(fd, holder[fd]);
	if (buff == NULL)
	{
		holder[fd] = NULL;
		return (NULL);
	}
	line = readline(buff);
	holder[fd] = newline(buff);
	return (line);
}
