/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:14:07 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 10:16:36 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//entry point of a philo,
//	philos wait to a set timestamp before starting to think
void	*life_of_a_philo(void *package)
{
	t_philos		*philo;
	unsigned long	time_to_start;

	philo = package;
	time_to_start = philo->info.time_init;
	while (time_() < time_to_start)
	{
		if (philo->id % 2 == 0)
			usleep(1000);
		else
			usleep(200);
	}
	if (philo->id % 2 == 0)
		usleep(philo->info.time_to_eat / 2 * 1000);
	think(*philo);
	return (NULL);
}
