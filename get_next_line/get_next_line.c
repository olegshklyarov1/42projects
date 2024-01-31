/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:33:21 by oshklyar          #+#    #+#             */
/*   Updated: 2023/12/04 16:22:12 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	char	*temp;
	int	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = ft_strdup("");
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(line, buffer);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		free(line);
		line = temp;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	if (bytes_read == -1 || (bytes_read == 0 && line[0] == '\0'))
	{
		free(line);
		return (NULL);
	}
	return (line);
}