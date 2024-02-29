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
#include <stdlib.h>

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		i++;
	while (last_node->buffer[i] && last_node->buffer[++i])
		buf[j++] = last_node->buffer[i];
	buf[j] = '\0';
	clean_node->buffer = buf;
	clean_node->next = NULL;
	free_all(list, clean_node, buf);
}

char	*get_line(t_list *list)
{
	int	len;
	char	*line;

	if (list == NULL)
		return (NULL);
	len = len_to_newline(list);
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	copy_str(list, line);
	return (line);
}

void	join(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buffer = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int	bytes_read;
	char	*buf;

	while (!find_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (!bytes_read)
		{
			free(buf);
			return ;
		}
		buf[bytes_read = '\0'];
		join(list, buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char	*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = get_line(list);
	clean_list(&list);
	return (next_line);
}