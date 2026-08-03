/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:53:29 by olshklya          #+#    #+#             */
/*   Updated: 2026/08/03 17:12:44 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	parse_and_init(int argc, char *argv[], t_data *data)
{
	if (!parse_args(argc, argv, data))
		return (0);
	if (!init_data(data))
		return (0);
	data->start_time = get_time();
	return (1);
}

int	init_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		data->philos[i].last_meal_time = data->start_time;
		i++;
	}
	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine,
				&data->philos[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	if (!parse_and_init(argc, argv, &data))
		return (1);
	if (!init_struct(&data))
		return (1);
	monitor(&data);
	i = 0;
	while (i < data.number_of_philos)
	{
		pthread_join(data.philos[i].thread, NULL);
		i++;
	}
	return (1);
}
