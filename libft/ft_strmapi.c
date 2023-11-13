/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:12:01 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/13 13:19:35 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char*))
{
	int		i;
	char	*dst;

	i = 0;
	if (!s || !f)
		return (NULL);
	dst = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dst)
		return (dst);
	while (s[i])
	{
		dst[i] = (*f)(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
