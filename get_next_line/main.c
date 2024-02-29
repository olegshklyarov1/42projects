/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:23:12 by oshklyar          #+#    #+#             */
/*   Updated: 2023/12/04 15:35:01 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;

	fd = open("file", O_RDONLY);
	if (fd == -1)
	{
		perror("error opening file");
		return (1);
	}
	
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;

        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
