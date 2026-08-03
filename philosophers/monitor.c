/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:47:27 by olshklya          #+#    #+#             */
/*   Updated: 2026/08/03 17:00:22 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

static int	check_death(t_data *data)
{
	int			i;
	long long	current_time;

	i = 0;
	while (i < data->number_of_philos)
	{
		current_time = get_time();
		if ((current_time - data->philos[i].last_meal_time) > data->time_to_die)
		{
			data->stop = 1;
			pthread_mutex_lock(&data->print_mutex);
			printf("%lld %d died\n", current_time - data->start_time,
				data->philos[i].id);
			pthread_mutex_unlock(&data->print_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_all_ate(t_data *data)
{
	int	i;

	if (data->must_eat < 0)
		return (0);
	i = 0;
	while (i < data->number_of_philos)
	{
		if (data->philos[i].meals_eaten < data->must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->state_mutex);
		if (check_death(data) || check_all_ate(data))
		{
			data->stop = 1;
			pthread_mutex_unlock(&data->state_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&data->state_mutex);
		usleep(500);
	}
	return (NULL);
}
