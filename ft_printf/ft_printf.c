/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:02 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/20 16:39:54 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(char input, va_list args)
{
	int		i;

	i = 0;
	if (input == 'c')
		i += print_char(va_arg(args, int));
	else if (input == 's')
		i += print_string(va_arg(args, char *));
	else if (input == 'p')
		i += print_pointer(va_arg(args, void *));
	else if (input == 'd')
		i += print_int(va_arg(args, int));
	else if (input == 'i')
		i += print_int(va_arg(args, int));
	/*else if (*input == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'x')
		i += print_hex(va_arg(args, unsigned int), 87);
	else if (*input == 'X')
		i += print_hex(va_arg(args, unsigned int), 55);*/
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list		args;
	unsigned int	i;
	int			len;
	
	if (!input)
		return (0);
	i = 0;
	len = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			len += check_type(input[i], args);
			if (input[i] == '%')
				i += print_char('%');
		}
		else
			len += write(1, &input[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
