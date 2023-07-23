/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 07:47:36 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 14:05:33 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

//checks if time since last meal is bigger than time to die
static int	is_dead(t_philos philo)
{
	if (time_since_last_meal(philo) > (unsigned long)philo.info.time_to_die)
	{
		return (TRUE);
	}
	return (FALSE);
}

//helper to faucheuse()
static void	end_simulation(t_philos *philos, int i)
{
	unsigned long	time_init;
	int				id;

	time_init = philos->info.time_init;
	id = philos[i].id;
	pthread_mutex_lock(philos->print_mutex);
	i = 0;
	while (i < (*philos).info.nb_of_philo)
		pthread_detach(philos[i++].thread);
	printf("%lu %d died :(\n", timestamp(time_init), id);
}

static void	check_if_done_eating(t_philos *philos, int i, int *count)
{
	pthread_mutex_lock(philos[i].last_meal_mutex);
	if (*philos[i].nb_of_meals == philos[i].info.nb_of_eat)
	{
		*philos[i].nb_of_meals = *philos[i].nb_of_meals + 1;
		pthread_detach(philos[i].thread);
		*count = *count + 1;
	}
	pthread_mutex_unlock(philos[i].last_meal_mutex);
}

//goes through all philosophers to check if they are dead
void	*faucheuse(void *package)
{
	t_philos		*philos;
	unsigned long	time_to_start;
	int				i;
	int				done_eating_count;

	done_eating_count = 0;
	philos = package;
	time_to_start = (*philos).info.time_init;
	while (time_() < time_to_start)
		usleep(500);
	while (TRUE)
	{
		i = 0;
		while (i < (*philos).info.nb_of_philo)
		{
			if (is_dead(philos[i]))
				return (end_simulation(philos, i), NULL);
			check_if_done_eating(philos, i, &done_eating_count);
			if (done_eating_count == (*philos).info.nb_of_philo)
				return (printf("\nAll philosophers have survived :)\n"), NULL);
			i++;
		}
	}
	return (NULL);
}
