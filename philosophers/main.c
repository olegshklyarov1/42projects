/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:53:29 by olshklya          #+#    #+#             */
/*   Updated: 2026/04/28 14:33:17 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"
#include <pthread.h>

int	main(int argc, char *argv[])
{
	t_data	data;
	pthread_t	monitor;
	int	i;

	if (!parse_args(argc, argv, &data))
		return (1);
	if (!init_data(&data))
		return (1);
	data.start_time = get_time();
	i = 0;
	while (i < data.number_of_philos)
	{
    	data.philos[i].last_meal_time = data.start_time;
    	i++;
	}
i = 0;
	while (i < data.number_of_philos)
	{
		pthread_create(&data.philos[i].thread, NULL,
			philo_routine, &data.philos[i]);
		i++;
	}
	pthread_create(&monitor, NULL, monitor_routine, &data);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < data.number_of_philos)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	return (0);
}