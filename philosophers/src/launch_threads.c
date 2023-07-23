/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macote <macote@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:07:03 by macote            #+#    #+#             */
/*   Updated: 2023/06/12 11:33:49 by macote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	launch_threads(t_philos *philos)
{
	pthread_t	death;
	int			i;

	i = 0;
	while (i < philos->info.nb_of_philo)
	{
		pthread_create(&philos[i].thread, NULL, &life_of_a_philo, &philos[i]);
		i++;
	}
	pthread_create(&death, NULL, &faucheuse, philos);
	pthread_join(death, NULL);
}
