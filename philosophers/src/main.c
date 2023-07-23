/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:59:40 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 13:49:31 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_all(t_philos *philo)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = (*philo).info.nb_of_philo;
	pthread_mutex_destroy((*philo).print_mutex);
	free((*philo).print_mutex);
	i = 0;
	while (i < nb_of_philos)
	{
		pthread_mutex_destroy(philo[i].left_fork);
		free(philo[i].left_fork);
		pthread_mutex_destroy(philo[i].last_meal_mutex);
		free(philo[i].last_meal_mutex);
		free(philo[i].last_meal);
		free(philo[i].nb_of_meals);
		i++;
	}
	free(philo);
}

//entry function of the program
void	*philosophers(int argc, char **argv)
{
	t_info		info;
	t_philos	*philos;

	info = parse_info(argc, argv);
	if (info.nb_of_philo <= 0)
		return (input_error(), NULL);
	philos = init_philos(info);
	launch_threads(philos);
	free_all(philos);
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (input_error(), 1);
	philosophers(argc, argv);
	return (0);
}
