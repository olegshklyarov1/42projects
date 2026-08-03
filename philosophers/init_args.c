/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:13:13 by olshklya          #+#    #+#             */
/*   Updated: 2026/08/03 16:57:29 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error(void)
{
	printf("Invalid usage or arguments.\n");
	return (0);
}

static int	atoi_dup(char *str, int *out)
{
	int	n;

	n = 0;
	if (!*str)
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		if (n > (INT_MAX - (*str - '0')) / 10)
			return (0);
		n = n * 10 + (*str++ - '0');
	}
	*out = n;
	return (1);
}

int	parse_args(int ac, char **av, t_data *data)
{
	int	tmp;

	if (ac < 5 || ac > 6)
		return (print_error());
	memset(data, 0, sizeof(t_data));
	data->must_eat = -1;
	if (!atoi_dup(av[1], &data->number_of_philos) || !atoi_dup(av[2], &tmp))
		return (print_error());
	data->time_to_die = tmp;
	if (!atoi_dup(av[3], &tmp))
		return (print_error());
	data->time_to_eat = tmp;
	if (!atoi_dup(av[4], &tmp))
		return (print_error());
	data->time_to_sleep = tmp;
	if (ac == 6 && !atoi_dup(av[5], &data->must_eat))
		return (print_error());
	if (data->number_of_philos < 1)
		return (printf("Philosophers number must be at least 1\n"), 0);
	return (1);
}
