/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:14:27 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 11:34:10 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//current day time in ms
unsigned long	time_(void)
{
	struct timeval	tv;
	unsigned long	time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (1000 * tv.tv_sec) + (tv.tv_usec / 1000);
	return (time_in_ms);
}

//time elapsed since beginning of simulation
unsigned long	timestamp(unsigned long time_init)
{
	return (time_() - time_init);
}

// time elapsed since last time a philo has eaten
unsigned long	time_since_last_meal(t_philos philo)
{
	unsigned long	last_meal;

	pthread_mutex_lock(philo.last_meal_mutex);
	last_meal = *philo.last_meal;
	pthread_mutex_unlock(philo.last_meal_mutex);
	return (timestamp(philo.info.time_init) - last_meal);
}
