/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:23:22 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/08 14:33:13 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*found;
	const char	*p;

	c = (unsigned char) c;
	if(c == '\0')
		return(ft_strchr(s, '\0'));
	found = NULL;
	while((p = ft_strchr(s, c)) != NULL)
	{
		found = p;
		s = p + 1;
	}
	return(char *) found;
}
