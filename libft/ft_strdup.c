/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:47:56 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/08 13:38:52 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	char		*p;
	int			len;

	len = 0;
	while (s1[len])
		len++;
	str = malloc(len + 1);
	p = str;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (p);
}
