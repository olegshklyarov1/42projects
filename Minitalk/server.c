#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_message
{
	unsigned char	current_char;
	int	bit_position;
	pid_t	client_pid;
	size_t	total_chars;
}	t_message;

static t_message g_msg = {0 , 0, 0, 0};

static void	handle_message(int sig, siginfo_t *info, void *context)
{

	(void)context;

	if (!g_msg.client_pid)
	{
		g_msg.client_pid = info->si_pid;
		ft_putstr_fd("\nNew client connection [", 1);
		ft_putnbr_fd(g.msg.client_pid, 1);
		ft_putstr_fd("]\n", 1);
	}
	g_msg.current_char = (g_msg.current_char << 1) | (sig == SIGUSR2);
	g_msg.bit_position++;
	if (g_msg.bit_position == 8)
	{
		if (!g_msg.current_char)
		{
			ft_putstr_fd("\nMessage received - ", 1);
			ft_putnbr_fd(g_msg.total_chars, 1);
			ft_putstr_fd(" characters\n", 1);
			kill(g_msg.client_pid, SIGUSR2);
			g_msg = (t_message){0, 0, 0, 0};
			return;
		}
		ft_putchar_fd(g_msg.current_char, 1);
		g_msg.total_chars++;
		g_msg.current_char = 0;
		g_msg.bit_position = 0;
		if (kill(g_msg.client_pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("\nError: disconnected client\n", 2);
			g_msg = (t_message){0, 0, 0, 0};
			return;
		}
	}
}

static void	setup_signals(void)
{
	struct sigaction sa;
	sa.sa_sigaction = handle_message;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_putstr_fd("ERROR : Impossible to configure signals\n", 2);
		exit(1);
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_putstr_fd("\n === Minitalk Server ===\nServer PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	setup_signals();
	while (1)
		pause();
	return (0);
}
