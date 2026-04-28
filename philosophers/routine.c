/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 16:26:26 by olshklya          #+#    #+#             */
/*   Updated: 2026/04/28 14:45:49 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <threads.h>

static int	is_stopped(t_data *data)
{
	int	stop;

	pthread_mutex_lock(&data->state_mutex);
	stop = data->stop;
	pthread_mutex_unlock(&data->state_mutex);
	return (stop);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "has taken a fork");
	}
	else 
	{
		pthread_mutex_lock(philo->left_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_state(philo, "has taken a fork");
	}
}

static void	eat(t_philo *philo)
{
	print_state(philo, "is eating");
	pthread_mutex_lock(&philo->data->state_mutex);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->data->state_mutex);
	ft_sleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	else if (philo->id == philo->data->number_of_philos)
		usleep(1000);
	while (!is_stopped(philo->data))
	{
		print_state(philo, "is thinking");
		take_forks(philo);
		if (is_stopped(philo->data))
		{
			pthread_mutex_unlock(philo->left_fork);
			pthread_mutex_unlock(philo->right_fork);
			break ;
		}
		eat(philo);
		print_state(philo, "is sleeping");
		ft_sleep(philo->data->time_to_sleep, philo->data);
	}
	return (NULL);
}