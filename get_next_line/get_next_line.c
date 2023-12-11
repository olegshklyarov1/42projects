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

char	*ft_readed_line(char *start)
{
	int		i;
	char	*line;

	if(!start || !start[0])
		return (NULL);
	i = 0;
	while (start[i] != '\n' && start[i])
		i++;
	if (start[i] == '\n')
	{
		i ++;
	}
	line = (char*)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (start[i] != '\n' && start[i])
	{
		line[i] = start[i];
		i++;
	}
	if (start[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_move_start(char *start)
{
	int		i;
	int		j;
	char	*ptr;

	while (start[i] != '\n' && start[i])
		i++;
	if (!start[i])
	{
		free(start);
		return (NULL);
	}
	i += (start[i] == '\n');
	ptr = (char*)malloc(ft_strlen(start) - i + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while (start[i + j])
	{
		ptr[j] = start[i + j];
		j++;
	}
	ptr[j] = '\0';
	free(start);
	return (ptr);
}

char	*get_next_line(int fd)
{
	char	*tmp;
	int		fd_read;
	static char	*start;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	fd_read = 1;
	tmp = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (!ft_strchr(start, '\n') && fd_read != 0)
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[fd_read] = '\0';
		start = ft_strjoin(start, tmp);
	}
	free(tmp);
	tmp = ft_readed_line(start);
	start = ft_move_start(start);
	return (tmp);
}