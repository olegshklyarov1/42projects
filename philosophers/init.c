/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:13:13 by olshklya          #+#    #+#             */
/*   Updated: 2026/04/28 14:45:28 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

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
		if (n > INT_MAX)
        	return (0);
		n = n * 10 + (*str++ - '0');
	}
	*out = n;
	return (1);
}
 
int	parse_args(int ac, char **av, t_data *data)
{
	if (ac < 5 || ac > 6)
		return (print_error());
	memset(data, 0, sizeof(t_data));
	data->must_eat = -1;
	if (!atoi_dup(av[1], &data->number_of_philos)
		|| !atoi_dup(av[2], (int *)&data->time_to_die)
		|| !atoi_dup(av[3], (int *)&data->time_to_eat)
		|| !atoi_dup(av[4], (int *)&data->time_to_sleep))
		return (print_error());
	if (ac == 6 && !atoi_dup(av[5], &data->must_eat))
		return (print_error());
	if (data->number_of_philos < 1)
	{
		printf("Philosophers number must be at least 1\n");
		return (0);
	}
	return (1);
}

static void	init_values(t_data *data, int i)
{
	
	i = 0;
	while (i < data->number_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].meals_eaten = 0;
		data->philos[i].last_meal_time = 0;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->number_of_philos];
		data->philos[i].data = data;
		i++;
	}
}

int	init_data(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	data->philos = malloc(sizeof(t_philo) * data->number_of_philos);
	if (!data->forks || !data->philos)
	{
		free(data->forks);
		free(data->philos);
		return (0);
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->state_mutex, NULL);
	i = 0;
	init_values(data, i);
	return (1);
}