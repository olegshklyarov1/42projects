/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:32:40 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/22 16:34:20 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_unsigned(unsigned int nb)
{
    int len;

    len = 0;
    if (nb >= 10)
    {
        len += print_unsigned(nb / 10);
        len += print_unsigned(nb % 10);
    }
    else
        len += print_char(nb + '0');
    return (len);
}
