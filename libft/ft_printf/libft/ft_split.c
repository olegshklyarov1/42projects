/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:13:27 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/13 12:12:25 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*s)
	{
		if (*s != c && !trigger)
		{
			trigger = 1;
			i++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static char	*ft_word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_alloc_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc ((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		index;
	char	**split;

	split = ft_alloc_split(s, c);
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
