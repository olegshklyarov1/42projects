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

int print_hex(long n, int base)
{
    int count;
    char *symbols;

    symbols = "0123456789abcdef";
    if (n < 0)
    {
        write(1, "-", 1);
        return (print_hex(-n, base) + 1);
    }
    else if (n < base)
    {
        return (print_char(symbols[n]));
    }
    else
    {
        count = print_hex(n / base, base);
        return (count + print_hex(n % base, base));
    }
}