/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:47:27 by olshklya          #+#    #+#             */
/*   Updated: 2026/04/28 14:28:36 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"
#include <pthread.h>

static int	check_death(t_data *data)
{
	int			i;
	long long	current_time;
	
	i = 0;
	current_time = get_time();
	while (i < data->number_of_philos)
	{
		if ((current_time - data->philos[i].last_meal_time) > data->time_to_die)
		{
			pthread_mutex_lock(&data->print_mutex);
			printf("%lld %d died\n", current_time - data->start_time, data->philos[i].id); 
			data->stop = 1;
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

void	*monitor_routine(void *arg)
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
		usleep(1000);
	}
};