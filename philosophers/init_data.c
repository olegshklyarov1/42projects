/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 17:35:34 by olshklya          #+#    #+#             */
/*   Updated: 2026/08/03 16:57:50 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	destroy_forks(t_data *data, int count)
{
	while (--count >= 0)
		pthread_mutex_destroy(&data->forks[count]);
	free(data->forks);
	free(data->philos);
	return (0);
}

static int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (destroy_forks(data, i));
		i++;
	}
	return (1);
}

static int	init_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (destroy_forks(data, data->number_of_philos));
	if (pthread_mutex_init(&data->state_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_mutex);
		return (destroy_forks(data, data->number_of_philos));
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
		data->philos[i].right_fork = &data->forks[(i + 1)
			% data->number_of_philos];
		data->philos[i].data = data;
		i++;
	}
}

int	init_data(t_data *data)
{
	data->forks = malloc(sizeof(pthread_mutex_t) * data->number_of_philos);
	if (!data->forks)
		return (0);
	data->philos = malloc(sizeof(t_philo) * data->number_of_philos);
	if (!data->philos)
	{
		free(data->forks);
		return (0);
	}
	if (!init_forks(data))
		return (0);
	if (!init_mutexes(data))
		return (0);
	init_values(data, 0);
	return (1);
}
