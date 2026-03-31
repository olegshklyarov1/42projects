/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:03:03 by olshklya          #+#    #+#             */
/*   Updated: 2026/03/10 18:09:14 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

static t_message	g_msg = {0, 0, 0, 0};

static char	*add_char_to_buffer(char *buffer, char c, int *buffer_len)
{
	char	*new_buffer;
	int		i;

	new_buffer = malloc(*buffer_len + 2);
	if (!new_buffer)
		return (NULL);
	i = 0;
	if (buffer)
	{
		while (i < *buffer_len)
		{
			new_buffer[i] = buffer[i];
			i++;
		}
		free(buffer);
	}
	new_buffer[i] = c;
	new_buffer[i + 1] = '\0';
	(*buffer_len)++;
	return (new_buffer);
}

static void	handle_end_message(char **buffer, int *buffer_len)
{
	ft_putstr_fd(*buffer, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Message received : ", 1);
	ft_putnbr_fd(g_msg.total_chars, 1);
	ft_putstr_fd(" characters\n", 1);
	free(*buffer);
	*buffer = NULL;
	*buffer_len = 0;
	kill(g_msg.client_pid, SIGUSR2);
	g_msg = (t_message){0, 0, 0, 0};
}

static void	handle_message(int sig, siginfo_t *info, void *context)
{
	static char	*buffer = NULL;
	static int	buffer_len = 0;

	(void)context;
	if (!g_msg.client_pid)
		g_msg.client_pid = info->si_pid;
	g_msg.current_char = (g_msg.current_char << 1) | (sig == SIGUSR1);
	kill(g_msg.client_pid, SIGUSR1);
	if (++g_msg.bit_position < 8)
		return ;
	if (!g_msg.current_char)
		return (handle_end_message(&buffer, &buffer_len));
	buffer = add_char_to_buffer(buffer, g_msg.current_char, &buffer_len);
	if (!buffer)
		return (ft_putstr_fd("Memory allocation failed\n", 2));
	g_msg.total_chars++;
	g_msg.current_char = 0;
	g_msg.bit_position = 0;
}

static void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_message;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("ERROR : Impossible to configure signals\n", 2);
		exit(1);
	}
}

int	main(void)
{
	ft_putstr_fd("\n === Minitalk Server ===\n Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	setup_signals();
	while (1)
	{
		pause();
	}
	return (0);
}
