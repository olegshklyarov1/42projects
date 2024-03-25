#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

static void	action ();

int	main(void)
{
	struct sigaction	s_sigaction;
	ft_putstr_fd("SERVER PID:     ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	s_sigaction.sa_sigaction = action;

	
	return (0);
}