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
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>

int	main(void)
{
	int	fd;
	char	buf[256];
	int	chars_read;

	fd = open("file.txt", O_RDONLY);
	while((chars_read = read(fd, buf, 5)))
	{
		buf[chars_read] = '\0';
		printf("buf-> %s\n", buf);
	}
}
