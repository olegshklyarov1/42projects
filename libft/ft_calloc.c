/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pohl <pohl@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:33:45 by pohl              #+#    #+#             */
/*   Updated: 2023/11/13 11:04:45 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	total;

	total = count * size;
	if (!(total))
		return (malloc(1));
	if (count > INT_MAX || size > INT_MAX)
		return (NULL);
	if (!count || !size)
		return (NULL);
	p = (void *)malloc(total);
	if (!p)
		return (NULL);
	ft_memset(p, 0, total);
	return (p);
}
