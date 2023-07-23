/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:49:20 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 13:47:45 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	release_forks(t_philos philo)
{
	pthread_mutex_unlock(philo.left_fork);
	pthread_mutex_unlock(philo.right_fork);
}

void	eat(t_philos philo)
{
	print_status(philo, "is eating");
	pthread_mutex_lock(philo.last_meal_mutex);
	*philo.last_meal = timestamp(philo.info.time_init);
	*philo.nb_of_meals = *philo.nb_of_meals + 1;
	pthread_mutex_unlock(philo.last_meal_mutex);
	wait_(philo.info.time_to_eat);
	release_forks(philo);
	sleep_(philo);
}
