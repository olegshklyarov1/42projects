/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:06:59 by olshklya          #+#    #+#             */
/*   Updated: 2026/03/10 18:15:15 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

static int	g_ack = 0;

static void	receive_signal(int sig)
{
	static int	bits = 0;
	static int chars = 0;

	if (sig == SIGUSR1)
	{
		g_ack = 1;
		if (++bits == 8)
		{
			bits = 0;
			++chars;
		}
	}
	else
	{
		ft_putnbr_fd(chars - 1, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

static void	send_byte(int pid, unsigned char byte)
{
	int	i;
	int	sig;

	i = 8;
	while (i--)
	{
		if (byte >> i & 1)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		kill(pid, sig);
		while (!g_ack)
			usleep(50);
		g_ack = 0;
	}
}

static void	mt_kill(int pid, char *str)
{
	while (*str)
		send_byte(pid, *str++);
	send_byte(pid, 0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		write(1, "Usage : <./client> <server_pid> <message>\n", 42);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		write(2, "Error: invalid or unreachable PID\n", 34);
		return (1);
	}
	ft_putstr_fd("Sent    : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received: ", 1);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	mt_kill(pid, argv[2]);
	while (1)
		pause();
	return (0);
}
