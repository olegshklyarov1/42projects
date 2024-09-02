/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:15:54 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/13 11:12:37 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if ((!dst || !src) && size == 0)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dst_len;
	j = 0;
	if (dst_len < size - 1 && size > 0)
	{
		while (src[j] && dst_len + j < size -1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (dst_len >= size)
		dst_len = size;
	return (dst_len + src_len);
}
