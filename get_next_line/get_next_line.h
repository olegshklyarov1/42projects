/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:29:54 by oshklyar          #+#    #+#             */
/*   Updated: 2023/12/04 15:46:11 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_list
{
	char	*str;
	struct s_list	*next;
}				t_list;

char *get_next_line(int fd);
int found_new_line(t_list *stash);
t_list *ft_lst_get_last(t_list *stash);
void read_and_stash(int fd, t_list **stash);
void add_to_stash(t_list **stash, char *buf, int readed);
void extract_line(t_list *stash, char **line);
void generate_line(char **line, t_list *stash);
void free_stash(t_list *stash);
void clean_stash(t_list **stash);
int ft_strlen(const char *str);

#endif
