/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:49:53 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 13:48:43 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//odd and even philos dont take same fork first to ensure
//	no deadlock
static void	which_fork_first(t_philos philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	if (philo.id % 2 == 0)
	{
		*first_fork = philo.right_fork;
		*second_fork = philo.left_fork;
	}
	else
	{
		*first_fork = philo.left_fork;
		*second_fork = philo.right_fork;
	}
}

//waits a little after sleeping if there is time
//	to let others eat if needed
static void	wait_a_little(t_philos philo)
{
	if (*philo.nb_of_meals != 0)
	{
		usleep(100);
		while (time_since_last_meal(philo)
			< (unsigned long)philo.info.time_to_die - (philo.info.time_to_eat
				* 1.2))
		{
			usleep(1000);
		}
	}
}

//lock first fork mutex
static void	take_first_fork(t_philos philo, pthread_mutex_t *first_fork)
{
	pthread_mutex_lock(first_fork);
	print_status(philo, "has taken a fork");
}

//lock second fork mutex
static void	take_second_fork(t_philos philo, pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(second_fork);
	print_status(philo, "has taken a fork");
}

void	think(t_philos philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	print_status(philo, "is thinking");
	which_fork_first(philo, &first_fork, &second_fork);
	wait_a_little(philo);
	take_first_fork(philo, first_fork);
	take_second_fork(philo, second_fork);
	eat(philo);
}
