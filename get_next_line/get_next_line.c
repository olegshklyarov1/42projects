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

void 	read_and_stash(int fd, t_list **stash)
{
	char 	*buf;
	int				readed;

	readed = 1;
	while (!found_new_line(*stash) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if (readed == -1 || (readed == 0 && !(*stash)))
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_stash(stash, buf, readed);
		free(buf);
	}
}

void 	add_to_stash(t_list **stash, char *buf, int readed)
{
	int 	i;
	t_list 	*new;
	t_list 	*last;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->str = malloc(sizeof(char) * (readed + 1));
	if (!new->str)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		new->str[i] = buf[i];
		i++;
	}
	new->str[i] = '\0';
	if (!(*stash))
	{
		*stash = new;
		return ;
	}
	last = ft_lst_get_last(*stash);
	last->next = new;
}

void 	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	generate_line(line, stash);
	if (!(*line))
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->str[i])
		{
			if (stash->str[i] == '\n')
			{
				(*line)[j++] = stash->str[i];
				break ;
			}
			*(line)[j++] = stash->str[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void 	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*clean;
	int		i;
	int		j;

	clean = malloc(sizeof(t_list));
	if (stash == NULL || clean == NULL)
		return ;
	clean->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->str[i] != '\n' && last->str[i])
		i++;
	if (last->str && last->str[i] == '\n')
		i++;
	clean->str = malloc(sizeof(char) * ((ft_strlen(last->str) - i) + 1));
	if (clean->str == NULL)
		return ;
	j = 0;
	while (last->str[i])
		clean->str[j++] = last->str[i++];
	clean->str[j] = '\0';
	free_stash(*stash);
	*stash = clean;
}

char 	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char					*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_and_stash(fd, &stash);
	if (stash == NULL)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
