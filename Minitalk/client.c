#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

static void signal_action(int sig)
{
    static int  receive = 0;
    if (sig == SIGUSR1)
        receive ++;
    else
    {
        ft_putnbr_fd(receive, 1);
        ft_putchar_fd('\n', 1);
        exit(0);
    }
}

void    ft_kill(int pid, char *str)
{
    int i;
    char    c;

    while (*str)
    {
        i = 8;
        c = *str ++;
        while (i --)
        {
            if (c >> i & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR2);
            usleep(100);
        }
    }
    i = 8;
    while (i --)
    {
        kill(pid, SIGUSR1);
        usleep(100);
    }
}

int main (int argc, char **argv)
{
    if (argc != 3 || !ft_strlen(argv[2]))
        return(1);
    ft_putstr_fd("SENT:     ", 1);
    

    return(0);
}