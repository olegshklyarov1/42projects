/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:29:53 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/22 16:32:22 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(long long int n, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789abcdef";
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n >= base)
		i += print_hex(n / base, base);
	print_char(str[n % base]);
	return (i + 1);
}

int	print_hex_upper(long long int n, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = "0123456789ABCDEF";
	if (n < 0)
	{
		n = -n;
		i++;
	}
	if (n >= base)
		i += print_hex_upper(n / base, base);
	print_char(str[n % base]);
	return (i + 1);
}
