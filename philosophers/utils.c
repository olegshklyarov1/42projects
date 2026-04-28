/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:07:00 by olshklya          #+#    #+#             */
/*   Updated: 2026/04/28 14:30:45 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_sleep(long long ms, t_data *data)
{
	long long	start;
	
	start = get_time();
	while ((get_time() - start) < ms)
	{
		pthread_mutex_lock(&data->state_mutex);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->state_mutex);
			return ;
		}
		pthread_mutex_unlock(&data->state_mutex);
		usleep(500);
	}
}

void	print_state(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	pthread_mutex_lock(&philo->data->state_mutex);
	if (!philo->data->stop)
		printf("%lld %d %s\n",
			get_time() - philo->data->start_time, philo->id, msg);
	pthread_mutex_unlock(&philo->data->state_mutex);
	pthread_mutex_unlock(&philo->data->print_mutex);
}