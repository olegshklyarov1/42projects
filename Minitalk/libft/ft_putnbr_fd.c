/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshklyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:41:15 by oshklyar          #+#    #+#             */
/*   Updated: 2023/11/13 15:10:46 by oshklyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	r;
	int	nbr;

	if (n == INT_MIN)
		write(fd, "-2147483648", 11);
	if (n > INT_MIN && n <= INT_MAX)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		r = n % 10;
		nbr = n / 10;
		r += 48;
		if (nbr > 0)
			ft_putnbr_fd(nbr, fd);
		write(fd, &r, 1);
	}
}
