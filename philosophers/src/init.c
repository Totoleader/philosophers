/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 11:19:07 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 13:49:02 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	set_right_fork(t_philos **philos, t_info info)
{
	int	i;

	i = 0;
	while (i < info.nb_of_philo)
	{
		if (i != info.nb_of_philo - 1)
			(*philos)[i].right_fork = (*philos)[i + 1].left_fork;
		else
			(*philos)[i].right_fork = (*philos)[0].left_fork;
		i++;
	}
}

t_philos	*init_philos(t_info info)
{
	pthread_mutex_t	*print_mutex;
	t_philos		*philos;
	int				i;

	print_mutex = malloc_mutex();
	pthread_mutex_init(print_mutex, NULL);
	philos = malloc_philos(info);
	i = 0;
	while (i < info.nb_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].last_meal = malloc_ul();
		philos[i].nb_of_meals = malloc_int();
		philos[i].left_fork = malloc_mutex();
		philos[i].last_meal_mutex = malloc_mutex();
		philos[i].right_fork = philos[i].left_fork;
		philos[i].info = info;
		philos[i].print_mutex = print_mutex;
		pthread_mutex_init(philos[i].last_meal_mutex, NULL);
		pthread_mutex_init(philos[i++].left_fork, NULL);
	}
	set_right_fork(&philos, info);
	return (philos);
}
