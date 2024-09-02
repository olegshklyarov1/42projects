/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                         :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:47:56 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/08 13:38:52 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getstart(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_getend(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;
	int		size;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	size = end - start;
	if (start >= end)
		return (ft_strdup(""));
	new = (char *)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1 + start, size + 1);
	return (new);
}
