/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:52:24 by oshklyar          #+#    #+#             */
/*   Updated: 2023/12/04 12:00:58 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	while(s[i])
		i++;
	return(i);
}

char	*ft_strchr(const char *s, char c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len_1;
	int		len_2;
	char	*str;

	if (s1 && s2)
	{
		len_1 = ft_strlen(s1);
		len_2 = ft_strlen(s2);
		str = (char *)malloc(sizeof (char) * (len_1 + len_2 + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len_1] = s2[i];
			len_1++;
		}
		str[len_1] = '\0';
		return (str);
	}
	return (NULL);
}

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

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}
