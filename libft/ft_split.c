/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:47:56 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/08 13:38:52 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' \
			|| c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

char	**ft_split(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	while(s[i])
	{
		if (ft_isspace(s[i]))
			i++;
		else
		{
			count++;
			while (s[i] && ft_isspace(s[i]) == 0)
				i++;
		}
	}
}
