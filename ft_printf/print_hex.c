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

int print_hex(unsigned int value)
{
    int len;

    len = 0;
    if (value >= 16)
    {
        len += print_hex(value / 16);
        len += print_hex(value % 16);
    }
    else
    {
        if (value < 10)
            len += print_char(value + '0');
        else
            len += print_char(value + 'a' - 10);
    }
    return (len);
}