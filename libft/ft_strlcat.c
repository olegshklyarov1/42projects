/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:15:54 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/08 15:55:03 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (dst[i] != '\0' && i < size)
		i ++;
	j = i;
	while (src[i - j] != '\0' && i < size - 1)
	{
		dst[i] = src[i -j];
		i++;
	}
	if (j < size)
		dst[i] = '\0';
	return (j + ft_strlen(src));
}
