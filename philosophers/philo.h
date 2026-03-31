/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <olshklya@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 19:56:16 by olshklya          #+#    #+#             */
/*   Updated: 2026/03/30 20:09:32 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <ctime>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int	id;
	int	meals_eaten;
	long long	last_meal_time;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data	*data;
}	t_philo;

typedef struct s_data
{
	int	number_of_philos;
	long long	time_to_die;
	long long	time_to_sleep;
	int	must_eat;
	int	stop;
	long long	start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t mutex_state;
	t_philo	*philos;
}	t_data;

long long	get_time(void);
void	ft_sleep(long long ms, t_data *data);
void	print_state(t_philo *philo, char *msg);
int	parse_args(int ac, char **av, t_data *data);
int	init_data(t_data *data);
void	clean(t_data *data);
void	*philo_routine(void *arg);
void	*monitoring_routine(void *arg);

#endif