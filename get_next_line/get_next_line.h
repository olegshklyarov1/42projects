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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}					t_list;

int					find_newline(t_list *list);
t_list				*find_last_node(t_list *list);
char				*get_line(t_list *list);
void				copy_str(t_list *list, char *str);
int					len_to_newline(t_list *list);
void				clean_list(t_list **list);
char				*get_next_line(int fd);
void				free_all(t_list **list, t_list *clean_node, char *buf);
void				create_list(t_list **list, int fd);

#endif