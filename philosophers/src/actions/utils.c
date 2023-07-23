/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:51:25 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 12:37:19 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//print function used in the program that locks print mutex to
//	make sure that timestamps are not tangled up
void	print_status(t_philos philo, char *str)
{
	pthread_mutex_lock(philo.print_mutex);
	printf("%lu %d %s\n", timestamp(philo.info.time_init), philo.id, str);
	pthread_mutex_unlock(philo.print_mutex);
}

//wait function for when a philo eats or sleeps
//	using usleep() if there is plenty of time to let priority to other threads
void	wait_(int time_to_wait)
{
	unsigned long	time_to_stop_waiting;

	time_to_stop_waiting = time_() + time_to_wait;
	while (time_() < time_to_stop_waiting - 5)
	{
		usleep(1000);
	}
	while (time_() < time_to_stop_waiting)
	{
	}
}
